#include <iostream>
#include <string>

/// virtual function
class virtualRoot{

public:
    virtual void someFunc(){
        std::cout << "root" << std::endl;
    }
};

class virtualChild: public virtualRoot {
public:
    void someFunc() override {
        std::cout << "child" << std::endl;
    }
};

/// pure virtual function
class pureVirtualRoot{
    
public:
    virtual void anotherFunc() = 0;
};

class pureVirtualChild: public pureVirtualRoot {
public:
    void anotherFunc() override {
        std::cout << "child" << std::endl;
    }
};


// pure virtual call

class A{
public:
    A(){
        foo();
    }
    void foo(){
        bar();
    }

    virtual void bar() = 0;
};

class B: public A{
public:
    void bar() override{ 
        std::cout << "pure" << std::endl;
    }
};


// virtual destructor

class virtualDestructorRoot{
public:
    virtualDestructorRoot(){
        std::cout << "Root constructor called" << std::endl;
    }

    virtual ~virtualDestructorRoot(){
        std::cout << "Root destructor called" << std::endl;
    }
};


class virtualDestructorChild: public virtualDestructorRoot {
public:
    virtualDestructorChild(){
        std::cout << "Child constructor called" << std::endl;
    }

    ~virtualDestructorChild(){
        std::cout << "Child destructor called" << std::endl;
    }

};


// Diamond problem 1 solution (call Device constructor 2 times)

class Device {
    public:
        Device() {
            std::cout << "Device constructor called" << std::endl;
        }
};

class Computer: public Device {
    public:
        Computer() {
            std::cout << "Computer constructor called" << std::endl;
        }
};

class Monitor: public Device {
    public:
        Monitor() {
            std::cout << "Monitor constructor called" << std::endl;
        }
};

class Laptop: public Computer, public Monitor {};


// Diamond problem 2 solution (call Device constructor 1 time)

// class Computer: virtual public Device {
//     public:
//         Computer() {
//             std::cout << "Computer constructor called" << std::endl;
//         }
// };

// class Monitor: virtual public Device {
//     public:
//         Monitor() {
//             std::cout << "Monitor constructor called" << std::endl;
//         }
// };

