#include <iostream>
#include <thread>
#include <string.h>
#include <mutex>
#include <vector>
#include <queue>

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



void retrieve_and_delete(std::queue<int>& rawQueue, std::string threadName) {
    if( !rawQueue.empty() ) {


        //door.lock();
        
        std::string out = "[ " + threadName + " ] front " + std::to_string(rawQueue.front());
        rawQueue.pop();
        out += " | new front " + std::to_string(rawQueue.front())  + "\n";
        std::cout << out;

        //door.unlock();

    }
}

