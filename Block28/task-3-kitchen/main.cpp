#include <iostream>
#include <thread>
#include <map>
#include <vector>
#include <ctime>
#include <mutex>

#define DELIVERY_TIME 30
#define ORDER_TIME (std::rand()%6+5)
#define MAKE_TIME (std::rand()%11+5)
#define DISH_TYPE ((Dishes)(std::rand()%5))

std::mutex mutex;

enum Dishes
{
    PIZZA,
    SOUP,
    STAKE,
    SALAD,
    SUSHI
};

std::map<Dishes, std::string> dishesDict
{
        {PIZZA, "PIZZA"},
        {SOUP, "SOUP"},
        {STAKE, "STAKE"},
        {SALAD, "SALAD"},
        {SUSHI, "SUSHI"}
};

void showDish(Dishes &dish)
{
    std::cout << dishesDict.at(dish) << std::endl;
}


class Restaurant
{
    int delivers{0};
    bool isOpen{true};
    std::vector<Dishes> dishesToDeliver{};
    std::vector<Dishes> orderedDishes{};

public:

    void getToDelivery()
    {
        while (true) {
            mutex.lock();
            if (dishesToDeliver.empty()) {
                mutex.unlock();
                continue;
            }
            std::cout << "\t\t---\nCourier takes to delivery:" << std::endl;
            for (auto & i : dishesToDeliver)
                showDish(i);
            ++delivers;
            dishesToDeliver.clear();
            if (delivers > 9) {
                isOpen = false;
                std::cout << "---\nEnd of the day!" << std::endl;
                mutex.unlock();
                break;
            }
            mutex.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(DELIVERY_TIME));
        }

    }

    void takeOrder()
    {
        while (true) {
            mutex.lock();
            if (!isOpen) {
                mutex.unlock();
                break;
            }
            mutex.unlock();
            std::this_thread::sleep_for(std::chrono::seconds(ORDER_TIME));
            Dishes order = DISH_TYPE;
            std::cout << "---\nOrder taken. Dish:" << std::endl;
            showDish(order);
            mutex.lock();
            orderedDishes.push_back(order);
            mutex.unlock();
        }

    }

    void makeDish()
    {
        while (true) {
            mutex.lock();
            if (!isOpen) {
                mutex.unlock();
                break;
            }
            if (orderedDishes.empty()) {
                mutex.unlock();
                continue;
            }
            Dishes current = orderedDishes.back();
            orderedDishes.pop_back();
            std::cout << "\t---\nKitchen makes order. Dish: " << std::endl;
            showDish(current);
            mutex.unlock();

            std::this_thread::sleep_for(std::chrono::seconds(MAKE_TIME));

            mutex.lock();
            dishesToDeliver.push_back(current);
            mutex.unlock();
        }
    }

};


int main()
{

    std::srand(std::time(nullptr));

    auto *restaurant = new Restaurant();

    std::thread kitchenThread([&restaurant](){restaurant->makeDish();});
    std::thread courierThread([&restaurant](){restaurant->getToDelivery();});
    std::thread makingOrdersThread([&restaurant](){restaurant->takeOrder();});

    courierThread.join();
    kitchenThread.join();
    makingOrdersThread.join();

    delete restaurant;

}