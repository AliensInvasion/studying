#include <iostream>
#include <vector>
#include <memory>

class Talents
{
public:
    virtual std::string talent() = 0;
    virtual ~Talents(){};
};

class Swimming : virtual public Talents
{
    virtual std::string talent() override
    {
        return "Swim";
    }
public:
    virtual ~Swimming() override {};
};

class Dancing : virtual public Talents
{
    virtual std::string talent() override
    {
        return "Dance";
    }
public:
    virtual ~Dancing() override {};
};

class Counting : virtual public Talents
{
    virtual std::string talent() override
    {
        return "Count";
    }
public:
    virtual ~Counting() override {};
};

class Dog
{
    std::string name{};
    std::vector<std::unique_ptr<Talents>> talents{};

public:

    void showTalents()
    {
        std::cout << "This is " << name << " and it has some talents: " << std::endl;
        for (auto &talent : talents) {
            std::cout << "\tIt can " << talent->talent() << std::endl;
        }
    }

    void setTalents()
    {
        char answer;
        std::cout << "Enter the name of the dog:" << std::endl;
        std::cin >> name;
        do {
            std::cout << "Can swim? 1/0" << std::endl;
            std::cin >> answer;
            if (answer == '1') {
                talents.push_back(std::make_unique<Swimming>());
            }
        } while (answer != '1' && answer != '0');
        do {
            std::cout << "Can dance? 1/0" << std::endl;
            std::cin >> answer;
            if (answer == '1') {
                talents.push_back(std::make_unique<Dancing>());
            }
        } while (answer != '1' && answer != '0');
        do {
            std::cout << "Can count? 1/0" << std::endl;
            std::cin >> answer;
            if (answer == '1') {
                talents.push_back(std::make_unique<Counting>());
            }
        } while (answer != '1' && answer != '0');
    }

};

int main()
{
    Dog dog;
    dog.setTalents();
    dog.showTalents();
}