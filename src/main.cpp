#include <iostream>
#include <cstdarg>
#include "some_code/header.h"

#define N STATICS

#define LAMBDA 1
#define MUTABLE 2
#define VIRTUAL 3
#define FRIEND 4
#define TEMPLATE 5
#define TRY 6
#define NAMESPACE 7
#define STATICS 8

#if N == LAMBDA
    #include "some_code/lambda.cpp"
#elif N == MUTABLE
    #include "some_code/mutable.cpp"
#elif N == VIRTUAL
    #include "some_code/virtual.cpp"
#elif N == FRIEND
    #include "some_code/friend.cpp"
#elif N == TEMPLATE
    #include "some_code/templates.cpp"
#elif N == TRY
    #include "some_code/try_catch.cpp"
#elif N == NAMESPACE
    #include "some_code/namespaces.cpp"
#elif N == STATICS
    #include "some_code/statics.cpp"

#endif 


using namespace staticThings;


int main(int argc, char **argv)
{

    //B *b = new B("B");
    return 0;
}