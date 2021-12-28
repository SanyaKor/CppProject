#include <iostream>
#include <thread>
#include <string.h>
#include <mutex>
#include <vector>
#include <queue>
#include <chrono>
#include "math.h"

unsigned long counter = 0;

std::mutex mtx1;
std::mutex mtx2;




void matrixOfElementsBAD(char ch, int dimensions){

    

    std::this_thread::sleep_for(std::chrono::milliseconds(300));


    {
        std::lock_guard<std::mutex> lg1(mtx1);

        for(int i = 0; i < dimensions; i++){
            for(int j = 0; j < dimensions; j++){
                std::cout << ch  << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    
}   

void matrixOfElementsBAD1(char ch, int dimensions){

    std::lock_guard<std::mutex> lg2(mtx1); /// 2

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::lock_guard<std::mutex> lg1(mtx2); /// 1


    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}   


void matrixOfElementsBAD2(char ch, int dimensions){

   
    std::lock_guard<std::mutex> lg1(mtx2); /// 1

    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::lock_guard<std::mutex> lg2(mtx1); /// 2

    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}   



void matrixOfElementsBETTER(char ch, int dimensions){

    std::lock(mtx1, mtx2);
   
    std::lock_guard<std::mutex> lg1(mtx2, std::adopt_lock); /// 1

    //std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::lock_guard<std::mutex> lg2(mtx1, std::adopt_lock); /// 2

    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}   


void matrixOfElementsBEST(char ch, int dimensions){

    std::scoped_lock sl(mtx1,mtx2);
   
    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}   
