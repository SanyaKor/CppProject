#include <iostream>
#include <thread>
#include <string.h>

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