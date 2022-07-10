#include <iostream>
#include <thread>
#include <functional>
#include <vector>
#include <map>

class Swimmer
{
    std::string name{"unknown"};
    double speed{0};
    double distance{0};
    int finalTime{0};

public:

    void swim()
    {
        while (distance < 100) {

            distance+=speed;
            finalTime+=1;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Swimmer " << name << ": " << distance << "m";
            std::cout << std::endl;

        }
    }

    int getFinalTime()
    {
        return finalTime;
    }

    std::string getName()
    {
        return name;
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


int main()
{
    Swimmer swimmers[6];

    for (auto &swimmer : swimmers) {
        swimmer.setName();
        swimmer.setSpeed();
    }

    std::thread threads[6];

    for (int i = 0; i < 6; ++i) {
        std::function<void()> function = ([&swimmers, &i](){swimmers[i].swim();});
        threads[i] = std::thread(function);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    for (auto &thread : threads) {
        thread.join();
    }

    std::map<int, std::vector<std::string>> results;

    for (auto &swimmer : swimmers) {
        int finalTime = swimmer.getFinalTime();
        auto it = results.find(finalTime);

        if (it == results.end()) {
            std::vector<std::string> names;
            names.push_back(swimmer.getName());
            std::pair<int, std::vector<std::string>> pair = std::make_pair(finalTime, names);
            results.insert(pair);
        } else {
            results[finalTime].push_back(swimmer.getName());
        }
    }

    std::cout << "--------------\nFinal scores: " << std::endl;
    std::cout << "--------------\n" << "Name: " << "\tResult(seconds):" << std::endl;
    for (auto &result : results) {
        for (int i = 0; i < result.second.size(); ++i) {
            std::cout << result.second[i] << "\t" << result.first << std::endl;
        }
    }
    std::cout << "--------------" << std::endl;
    
}