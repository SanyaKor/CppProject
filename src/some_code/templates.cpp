
template <typename FirstType, typename SecondType>
auto  templateFunction(FirstType t1, SecondType t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}



template < typename FirstType, typename SecondType>
class templateClass{
public:
    FirstType value_1;
    SecondType value_2;

    templateClass(FirstType value_1, SecondType value_2){
        this->value_1 = value_1;
        this->value_2 = value_2;
    }

    void print(){

        std::cout << value_1 << std::endl;
        std::cout << value_2 << std::endl;
    }
    auto sum() -> decltype (value_1 + value_2){ return value_1 + value_2; }
};



template < typename AnotherType, typename ... Args> 
void variableArguments(AnotherType value, Args ... args)
{
    std::cout << "smth" <<std::endl;
    func(args...);
}

template <class T>
void initializerList( std::initializer_list<T>  l ){
    std::cout << l.size() << std::endl;
}


// x = 3.4
// decltype(x) y = 4.5

// decltype(x++) y = 4.5 make the same thing

//template < typename FirstType, typename SecondType = int >


//template <class T, int max>