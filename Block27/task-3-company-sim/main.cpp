#include <iostream>

enum TaskType
{
    NONE = -1,
    A,
    B,
    C
};

class Laborer
{
    int id = -1;
    std::string name = "unknown";
    TaskType currentTask = NONE;
    static int count;

public:

    int getId()
    {
        return id;
    }

    static void countPlus()
    {
        ++count;
    }

    static int getCount()
    {
        return count;
    }

    std::string getName()
    {
        return name;
    }

    void setLabor(TaskType inTask)
    {
        currentTask = inTask;
        char temp = ((int)currentTask)+65;
        std::cout << "\t\tLaborer " << name << " with ID = " << getId() << " get the task of type " << temp << std::endl;
    }

    void setId(int inId)
    {
        id = inId;
    }

    void setName()
    {
        std::cout << "Enter the name of employee:" << std::endl;
        std::cin >> name;
        //name = "";
        //name += (std::rand()%10)+48;
        //name += (std::rand()%10)+48;
        //name += (std::rand()%10)+48;
        //name += (std::rand()%10)+48;
        //std::cout << name << std::endl;
    }

    TaskType getCurrentTask()
    {
        return currentTask;
    }

};

class Manager : Laborer
{
    int laborersCount = 0;
    Laborer **laborers = nullptr;

public:

    bool executeTask(int seed)
    {
        std::cout << "\nManager " << getName() << " with ID = " << getId() << " get the task with seed = " << seed << std::endl;
        seed += getId();
        std::srand(seed);

        //std::cout << "Laborers count " << laborersCount << std::endl;
        int tasks = 0;
        tasks = std::rand()%laborersCount+1;
        //std::cout << "Tasks to give: " << tasks << std::endl;
        int count = 0;
        for (int i = 0; i < laborersCount && count < tasks; ++i) {

            TaskType toDo = TaskType(std::rand()%3);

            if (laborers[i]->getCurrentTask() == NONE) {
                ++count;
                laborers[i]->setLabor(toDo);
            }
        }
        if (count == 0) return false;
        else return true;
    }

    Manager()
    {
        countPlus();
        std::cout << "Employee position: manager" << std::endl;
        setId(getCount());
        setName();
        std::cout << "Enter the number of employees in the team of manager " << getName() << ":" << std::endl;
        int team = 0;
        std::cin >> team;
        laborersCount = team;
        std::cout << laborersCount << std::endl; //!!
        laborers = new Laborer*[team];

        for (int i = 0; i < team; ++i) {
            countPlus();
            std::cout << "Employee position: laborer" << std::endl;
            laborers[i] = new Laborer;
            laborers[i]->setId(getCount());
            laborers[i]->setName();
        }
    }
};


class Head : Laborer
{
    int managersCount = 0;
    Manager **managers = nullptr;

public:

    bool initiateTask()
    {
        bool haveUnoccupied = false;
        std::cout << "Head " << getName() << " with ID = " << getId() << std::endl;
        std::cout << "Have a new task to initiate?" << std::endl;
        std::cout << "Enter the seed of the task:" << std::endl;
        int seed = 0;
        std::cin >> seed;
        for (int i = 0; i < managersCount; ++i) {
            if (managers[i]->executeTask(seed) == true) {
                haveUnoccupied = true;
            };
        }
        return haveUnoccupied;
    }

    Head()
    {
        countPlus();
        std::cout << "Employee position: head" << std::endl;
        setId(getCount());
        setName();
        std::cout << "Enter the number of teams:" << std::endl;
        int teams = 0;
        std::cin >> teams;
        managersCount = teams;
        managers = new Manager*[teams];
        for (int i = 0; i < teams; ++i) {
            managers[i] = new Manager;
        }
    }

};

int Laborer::count = 0;

int main()
{

    Head *head = new Head;
    bool haveUnoccupied = head->initiateTask();
    while (haveUnoccupied) {
        haveUnoccupied = head->initiateTask();
    }
    std::cout << "All employees are occupied!" << std::endl;
    delete head;
}