#include <iostream>

#define N VIRTUAL

#define LAMBDA 1
#define MUTABLE 2
#define VIRTUAL 3

#if N == LAMBDA
    #include "some_code/lambda.h"
#elif N == MUTABLE
    #include "some_code/mutable.h"
#elif N == VIRTUAL
    #include "some_code/virtual.h"
#endif 

int main(int argc, char **argv)
{
    Laptop l;
    return 0;
}