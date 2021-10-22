#include <iostream>

#define N MUTABLE

#define LAMBDA 1
#define MUTABLE 2


#if N == LAMBDA
    #include "some_code/lambda.h"
#elif N == MUTABLE
    #include "some_code/mutable.h"
#endif 

int main(int argc, char **argv)
{

    return 0;
}