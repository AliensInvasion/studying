#include <iostream>

class Toy
{
    std::string name;
public:
    Toy(std::string inName = "unnamed") : name(inName){}
};

class PtrCounter
{
    Toy* toyPtr{nullptr};
    int count{0};

public:

    PtrCounter() = default;

    PtrCounter(Toy* inToyPtr) : toyPtr(inToyPtr){}

    void operator++()
    {
        ++count;
    }
    void operator--()
    {
        if (count > 0)
            --count;
        if (count < 1)
        {
            delete toyPtr;
            toyPtr = nullptr;
        }
    }

};

class shared_ptr_toy
{
    PtrCounter* ptrCounter{nullptr};

public:

    shared_ptr_toy(std::string name = "unnamed")
    {
        Toy* toyPtr = new Toy(std::move(name));
        ptrCounter = new PtrCounter(toyPtr);
        ++*ptrCounter;
    }

    shared_ptr_toy(const shared_ptr_toy& other)
    {
        ptrCounter = new PtrCounter;
        ptrCounter = other.ptrCounter;
        ++*ptrCounter;
    }

    void reset()
    {
        if (ptrCounter == nullptr) return;
        --*ptrCounter;
        ptrCounter = nullptr;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other)
    {
        if (&other == this)
            return *this;
        reset();
        ptrCounter = other.ptrCounter;
        ++*ptrCounter;
        return *this;
    }

    ~shared_ptr_toy()
    {
        reset();
    }
};


shared_ptr_toy make_shared_toy(std::string name)
{
    shared_ptr_toy newToy(std::move(name));
    return newToy;
}

shared_ptr_toy make_shared_toy(const shared_ptr_toy& inToy)
{
    const shared_ptr_toy& newToy(inToy);
    return newToy;
}

class Dog
{
    shared_ptr_toy mySharedToy;

public:

    Dog()
    {
        mySharedToy = {};
    }

    Dog(const shared_ptr_toy& inToy) : mySharedToy(inToy) {}

    shared_ptr_toy& getMyToy()
    {
        return mySharedToy;
    }

    void copyToy(const Dog& other)
    {
        mySharedToy = other.mySharedToy;
    }
};

int main()
{
    shared_ptr_toy ball = make_shared_toy("Ball");
    shared_ptr_toy bone = make_shared_toy("Bone");
    shared_ptr_toy ball2 = make_shared_toy(ball);


    Dog a(ball), b(bone), c(ball2), d;

    d.copyToy(c);

    b.copyToy(d);

    a.copyToy(b);

    ball.reset();
    bone.reset();
    ball2.reset();

    a.getMyToy().reset();
    b.getMyToy().reset();
    c.getMyToy().reset();
    a.getMyToy().reset();

}
