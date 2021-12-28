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

void matrixOfElementsGOOD(char ch, int dimensions){

    std::unique_lock<std::mutex> lg1(mtx1, std::defer_lock);
    std::unique_lock<std::mutex> lg2(mtx2, std::defer_lock);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::lock(mtx2,mtx1);

    for(int i = 0; i < dimensions; i++){
        for(int j = 0; j < dimensions; j++){
            std::cout << ch  << " ";
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    mtx1.unlock();
    mtx2.unlock();    
}
