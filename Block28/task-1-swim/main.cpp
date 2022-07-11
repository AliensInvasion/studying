#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mutex;

class Swimmer
{
    std::string name{"unknown"};
    double speed{0};
    double distance{0};
    int finalTime{0};

    static std::vector<std::pair<int, std::string>> results;

public:

    static void getResults();

    void swim()
    {
        while (distance < 100) {
            distance+=speed;
            finalTime+=1;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Swimmer " << name << ": " << distance << "m";
            std::cout << std::endl;
        }

        mutex.lock();
        results.emplace_back(finalTime, name);
        mutex.unlock();

    }

    void setName()
    {
        std::cout << "Enter the name of the swimmer:" << std::endl;
        std::cin >> name;
    }

    void setSpeed()
    {
        std::cout << "Enter the speed of the swimmer (m/s):" << std::endl;
        std::cin >> speed;
    }

};

std::vector<std::pair<int, std::string>> Swimmer::results{};
void Swimmer::getResults()
{
    std::cout << "--------------\nFinal scores: " << std::endl;
    std::cout << "--------------\n" << "Name: " << "\t\tResult(seconds):" << std::endl;
    for (auto & result : results) {
        std::cout << result.second << "\t\t" << result.first << std::endl;
    }
    std::cout << "--------------" << std::endl;
}

int main()
{
    Swimmer swimmers[6];

    for (auto &swimmer : swimmers) {
        swimmer.setName();
        swimmer.setSpeed();
    }

    std::thread threads[6];

    for (int i = 0; i < 6; ++i) {
        threads[i] = std::thread([&swimmers, &i](){swimmers[i].swim();});
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    Swimmer::getResults();
    
}