#include <iostream>
#include <string.h>

class constChanger {
    int value;
    mutable std::string valueStr;

public:
    
    constChanger(int value, std::string valueStr){
        this->value = value;
        this->valueStr = valueStr;
    }

    void getValue() const {
        std::cout << "value: " << value << std::endl;
        std::cout << "valueStr: " << valueStr << std::endl;
    }

    void setValueStr(std::string newValue) const {
        valueStr = newValue;
    }

};

void lambda_capture(){
    int value = 0;

    auto lambda{
        [value]() mutable {
            value++;
            std::cout << "value: " << value << std::endl;
        }
    };
}