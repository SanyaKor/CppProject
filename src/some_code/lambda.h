#include <algorithm>
#include <iostream>
#include <string.h>
#include "vector"

//std::vector<std::string> vec{ "apple", "banana", "walnut", "lemon" };



std::vector<int> nums{3, 4, 2, 8, 15, 267};

void lambdaS(){
    int value = 0;

    int a = 1;
    int b = 1;
    int c = 1;
    
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


    // [value] 
    std::for_each(nums.begin(),nums.end(), 
        [value](const int& n) mutable {
            value+=n;
            //std::cout << value << std::endl;
        }
    );
    
    // [&value]
    std::sort(nums.begin(),nums.end(),
        [&value](const int& number1, const int& number2) {
            value++;
            return number1 < number2;
        } 
    );
    std::cout << "Comparisons: " << value << std::endl;
    
    // [=] -> []() value_1 += 1; value_2 += 1; {} all values () 
    std::for_each(nums.begin(),nums.end(), 
        [=](const int& n) mutable {
            a+=a;
            b+=b;
            //std::cout << a << " " << b << std::endl;
        }
    );
    //std::cout << a << " " << b << std::endl;

    // [=,&c] ... [&] ... [a,b, &c] .. etc ..


}