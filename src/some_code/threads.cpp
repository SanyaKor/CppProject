#include <iostream>
#include <thread>
#include <string.h>
#include <mutex>
#include <vector>
#include <queue>
#include <chrono>
#include "math.h"

std::mutex door;

void tFunction(){
    std::cout << "tFunction" << std::endl;
}

void tAnotherFunction( std::string msg ){
    for ( int i = 0; i < 10; i++ ){
            std::string result = "tAnotherFunction " + msg + " " + std::to_string(i);
            std::cout << result << std::endl;
    }
}

void runA( bool &value, int i ){
    if(value){
        std::string out = "[ " + std::to_string(i) + " ] value " + std::to_string(value)  + "\n";
        std::cout << out;

    }
}

void runB(bool& value) {
    value = false;
}



void retrieveDelete(std::queue<int>& rawQueue, std::string threadName) {
    if( !rawQueue.empty() ) {

        std::lock_guard<std::mutex> lock(door);

        //door.lock();

        std::string out = "[ " + threadName + " ] front " + std::to_string(rawQueue.front());
        rawQueue.pop();
        out += " | new front " + std::to_string(rawQueue.front())  + "\n";
        std::cout << out;

        //door.unlock();

    }
    // lock_guard makes door.unlock() here 
}


void SomeProcess(){

    std::this_thread::sleep_for(std::chrono::seconds(1));

    for(size_t i=0; true ;i++){
        //std::thread::id this_id = std::this_thread::get_id();
        std::cout << " thread id : " << std::this_thread::get_id()  << "\tanother proccess\t"  << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}

void PowProcess( double &a, int power ){

    std::this_thread::sleep_for(std::chrono::seconds(2));

   
    std::cout << " thread id : " << std::this_thread::get_id() << "\tPowProcess started\t"  << 0 << std::endl;
    a =  pow(a, power);
    std::this_thread::sleep_for(std::chrono::seconds(4));

    std::cout << " thread id : " << std::this_thread::get_id() << "\tPowProcess finished\t"  << 0 << std::endl;
}


double SumProcess(double a,double b, double c){
    double result;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << " thread id : " << std::this_thread::get_id() << "\tSumProcess started\t"  << 0 << std::endl;
    result = a+b+c;
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << " thread id : " << std::this_thread::get_id() << "\tSumProcess finished\t"  << 0 << std::endl;
    return result;
}



class SomeProcesses{
public:
    void VoidProcess(){
        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::cout << " thread id : " << std::this_thread::get_id() << "\tVoidProcess started\t"  << 0 << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(5));

        std::cout << " thread id : " << std::this_thread::get_id() << "\tVoidProcess finished\t"  << 0 << std::endl;
    }


};


void matrixOfElements(char ch, int dimensions){

    door.lock();
    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    door.unlock();
}   