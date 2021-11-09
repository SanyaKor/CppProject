#include <iostream>
#include "vector"



void tryCatchFunc(int index){

  std::vector<int> vec = {1,2,3,4,5};

  try {


    if (vec.size() >= index ) {

      std::cout << "Access granted " << vec[index] ;

    } else {

      throw (index);
    
    }

  }
  catch (int myNum) {
    std::cout << "Access denied \n";
  }
}

double exceptHere(double x,double y){
  if( y == 0 )
    throw ("division by zero");
  return x/y;  
}

double exceptAlsoHere(double x,double y) noexcept {
//if( y == 0 )
    //throw ("division by zero");
  return x/y;  
}

// noexcept( ... ) operator
// noexcept { spec
// noexcept ( noexcept ( f(x) ) ) 
// also make th sme thing (new,typeid)



void noExcepts(double (*f)(double ,double )){

  if(!noexcept(f(0,0)))
    std::cout << "except" << std::endl;
  else
    std::cout << "noexcept" << std::endl;
}


