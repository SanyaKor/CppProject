#include <iostream>

#define N LAMBDA

#define LAMBDA 1
#define MUTABLE 2


#if N == LAMBDA
    #include "some_code/lambda.h"
#elif N == MUTABLE
    #include "some_code/mutable.h"
#endif 

int main(int argc, char **argv)
{
    lambdaS();
    return 0;
}