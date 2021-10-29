#include <iostream>
#include <string>
namespace staticThings{


    class A{
    public: 
        A(std::string name ){
            this->name = name;
            index++;
        }
        void print(){
            std::cout << name << " " << index << std::endl;
        }

        static int index;
    private:
        std::string name;
    };
    int A::index = 0;


    class B{
    public: 
        B(std::string name ){
            this->name = name;
            index++;
        }
        static int getIndex(){
            return index;
        }

        
    private:
        static int index;
        std::string name;
    };
    B::
    

}