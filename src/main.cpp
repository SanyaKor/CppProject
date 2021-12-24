#include <iostream>
#include <cstdarg>
#include "some_code/header.h"
#include "some_code/Timer.cpp"

#define N THREADS

#define LAMBDA 1
#define MUTABLE 2
#define VIRTUAL 3
#define FRIEND 4
#define TEMPLATE 5
#define TRY 6
#define NAMESPACE 7
#define STATICS 8
#define THREADS 9

//static constexpr int TEST = 1; 

#if N == LAMBDA
    #include "some_code/lambda.cpp"
#elif N == MUTABLE
    #include "some_code/mutable.cpp"
#elif N == VIRTUAL
    #include "some_code/virtual.cpp"
#elif N == FRIEND
    #include "some_code/friend.cpp"
#elif N == TEMPLATE
    #include "some_code/templates.cpp"
#elif N == TRY
    #include "some_code/try_catch.cpp"
#elif N == NAMESPACE
    #include "some_code/namespaces.cpp"
#elif N == STATICS
    #include "some_code/statics.cpp"
#elif N == THREADS
   #include "some_code/threads.cpp"
    
#endif 




int main(int argc, char **argv)
{
    Timer timer;

    
    std::thread th1(Print1,'$',10);
    //std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::thread th2(Print2,'#',10);


    timer.start();

    th1.join();
    th2.join();

    timer.stop();
    std::cout << timer.elapsedMilliseconds() << std::endl;


    return 0;
}