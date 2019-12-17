#pragma once 
// header guard - if this file is included many times then only one instance will be actually used 
#include <string>
#include <iostream>
#include <vector>

class Observer // abstrac calss because has one method that's pure virtual
{
public:
    virtual void notify() = 0; // pure virtual method
    virtual ~Observer() = default;
};

class ExampleObserver : public Observer // inheritance
{//private by default 
    constexpr static auto name = "ExampleObserver";
    static unsigned counter;
public:
    ExampleObserver() : m_Counter{counter++} {}

    void notify() override
    {
        std::cout<<name<<" "<<m_Counter<<" received a notification"<<std::endl;
    }

    const unsigned m_Counter;
};

unsigned ExampleObserver::counter = 0;

class ExampleSubscriber
{
public:
    void addObserver(Observer* observer)
    {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer)
    {
        const auto result = std::find(observers.begin(), observers.end(), observer);

        if(result != observers.end())
        {
            observers.erase(result);
        }
    }

    void notifyObservers()
    {
        for(auto observer : observers)
        {
            observer->notify();
        }
    }
private:
    std::vector<Observer*> observers;
};

void run()
{
    ExampleSubscriber subscriber;
    ExampleObserver obs1;
    ExampleObserver obs2;
    ExampleObserver obs3;

    subscriber.addObserver(&obs1);
    subscriber.addObserver(&obs2);
    subscriber.addObserver(&obs3);

    subscriber.notifyObservers();
}