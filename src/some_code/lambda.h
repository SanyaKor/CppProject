#include <algorithm>
#include <iostream>
#include <string.h>
#include "vector"

//std::vector<std::string> vec{ "apple", "banana", "walnut", "lemon" };



std::vector<int> nums{3, 4, 2, 8, 15, 267};

void lambdaS(){
    int value = 123;

    auto print{
        [](const int& n) {
            std::cout << " " << n;
        }
    };

    // []
    auto find{
        [value](const int& n) {
            return n == value;
        }
    };
    
    std::for_each(nums.begin(),nums.end(),print);
    std::cout << std::endl;
    auto it = std::find_if(nums.begin(), nums.end(), find);

    

}