#pragma once

#include <memory>

class Resource
{
public: 
    Resource() = default;
    void doSomething() {}
};

class CellPhone : public Resource 
{ 
public: 
    CellPhone() = default;
    CellPhone(const char*) {};
};

class Event {};
class BestEventEver : public Event {};

class Subscriber
{
public:
    template<typename Res>
    Subscriber& addResource(Res&& res)
    {
        //add resource 
        return *this;
    }

    void notifyAll(){}
    void notifyAll(Resource&) {}
    void notifyAll(Event&&) {}
};

template<typename Res>
class Wrapper : public Res
{
public:
    Wrapper(Subscriber& s) : m_Sub{s} {}

    void doSomething()
    {
        Res::doSomething(); // ResDoSomething
        m_Sub.notifyAll(*(static_cast<Res*>(this)));
    }

    Subscriber& m_Sub;
};

void run()
{
    Subscriber subscriber;
    subscriber.addResource(CellPhone{"123456789"});
    subscriber.addResource(CellPhone{"987654321"}).notifyAll();

    subscriber.notifyAll(BestEventEver{});

    CellPhone phone{};
    subscriber.addResource(phone);
    subscriber.notifyAll(phone);

    Wrapper<CellPhone> wrappedPhone{subscriber};
    subscriber.addResource(wrappedPhone);

    wrappedPhone.doSomething(); // automatically notify
}



// template<typename Observer, typename...Args>
// void addObserver(Args&&...args) 
// {
//     observers.emplace([this](){ return this->getResources(); }, std::forward<Args>(args)...);
// }
