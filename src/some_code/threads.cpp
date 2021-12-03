#include <iostream>
#include <thread>
#include <string.h>
#include <mutex>
#include <vector>
#include <queue>
#include <chrono>


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

    for(int i=0; i<10 ;i++){
        std::cout << " thread id : " << std::this_thread::get_id() << "\tanother proccess\t" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

}