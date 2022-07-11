#include <iostream>
#include <thread>
#include <mutex>

std::mutex stationLock;

class Train
{
    char name;
    int arrivalTime = 0;

public:

    Train(char inName) : name(inName)
    {
    }

    char getName()
    {
        return name;
    }

    void setArrivalTime(int time)
    {
        arrivalTime = time;
    }

    void run()
    {
        for (int i = arrivalTime; i > 0; --i) {
            //std::cout << "Train " << name << " runs..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::cout << "Train " << name << " is waiting for place at the station." << std::endl;
        stationLock.lock();
        std::cout << "Train " << name << " has arrived to station. Waiting for depart:" << std::endl;
        std::string request;
        do {
            std::cin >> request;
        } while (request != "depart");
        std::cout << "Train " << name << " departed!" << std::endl;
        stationLock.unlock();
    }
};

int main()
{
    Train trains[3]{'A','B','C'};
    for (auto& train : trains) {
        std::cout << "Set arrival time for train " << train.getName() << ":" << std::endl;
        int time;
        std::cin >> time;
        train.setArrivalTime(time);
    }
    std::thread threads[3];

    for (int i = 0; i < 3; ++i) {
        threads[i] = std::thread([&trains, &i](){trains[i].run();});
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    for (auto & thread : threads) {
        thread.join();
    }

}