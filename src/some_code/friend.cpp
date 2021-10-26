#include <iostream>


class friendlyC{
int value;
public:
    friendlyC(int val): value(val){}
    void print(){
        std::cout << value << std::endl;
    }

    friend void setValue(friendlyC &friendlyC, int val);
};

void setValue(friendlyC &friendly, int val){
    friendly.value = val;
}
