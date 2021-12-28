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
   #include "some_code/multithreading/shared_lock.cpp"
    
#endif 




int main(int argc, char **argv)
{
    Timer t;

    std::vector<std::thread> threads;

    //for (int i = 0; i < 100; i++) {
    threads.push_back(std::thread(Incrementer));
    threads.push_back(std::thread(ImJustAReader));
    //}

    for (std::thread &t : threads) {
        t.join();
    }
    std::cout << "g_counter: " << g_counter << std::endl;

  
    return 0;
}