#include <iostream>
#include <thread>
#include <string.h>
#include <mutex>
#include <shared_mutex>
#include <vector>
#include <queue>
#include <chrono>
#include "math.h"

std::shared_mutex g_shared_mutex;
unsigned long g_counter = 0;

void Incrementer() {
    for (size_t i = 0; i < 100; i++) {
        std::unique_lock<std::shared_mutex> ul(g_shared_mutex);
        g_counter++;
    }
}

void ImJustAReader() {
    for (size_t i = 0; i < 100; i++) {
        std::shared_lock<std::shared_mutex> sl(g_shared_mutex);
        std::cout << "g_counter: " << g_counter << std::endl;
    }
}



