#include <iostream>
#include <cstdarg>
#include "some_code/header.h"


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
    
    double a=3;
    double result=0.0;
    std::thread MyThread1(PowProcess,std::ref(a),3);
    std::thread MyThread2([&result, &a](){ result = SumProcess(a,2,1);});

    //MyThread.detach();
    
    
    for(size_t i=0; i<10 ;i++){
        std::cout << " thread id : " << std::this_thread::get_id() << "\tmain\t"  << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
    }
    MyThread1.join();
    MyThread2.join();
    std::cout << "SumProcess result : " << a << std::endl;

    std::cout << "SumProcess result : " <<  result << std::endl;

    return 0;
}