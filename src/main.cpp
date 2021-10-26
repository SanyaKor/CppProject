#include <iostream>
#include <cstdarg>


#define N TRY

#define LAMBDA 1
#define MUTABLE 2
#define VIRTUAL 3
#define FRIEND 4
#define TEMPLATE 5
#define TRY 6

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

#endif 


double f(double x){
    return 0.0;
}



int main(int argc, char **argv)
{
    //noExcepts(exceptAlsoHere);
    
    return 0;
}