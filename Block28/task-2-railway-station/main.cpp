#include <iostream>
#include <thread>
#include <functional>
#include <mutex>

std::mutex stationLock;

class Train
{
    char name;
    int arrivalTime = 0;

public:

    Train(char inName) : name(inName)
    {
        std::cout << "Enter arrival time of train " << name << ":" << std::endl;
        std::cin >> arrivalTime;
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
    std::thread threads[3];

    for (int i = 0; i < 3; ++i) {
        std::function<void()> function = ([&trains, &i](){trains[i].run();});
        threads[i] = std::thread(function);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    for (int i = 0; i < 3; ++i) {
        threads[i].join();
    }

}