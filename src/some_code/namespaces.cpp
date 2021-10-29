#include <iostream>
//#pragma once


namespace namespaceTest{

    void namespaceFunction(){
        std::cout << "hi" << std::endl;
    }

}


namespace{
    class A{

    public:
        int value;
        A(int val): value(val){}  
    };
}

// static class A{}; error