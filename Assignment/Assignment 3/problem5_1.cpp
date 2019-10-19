/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 9, 2019
    PROB #: problem 5.1
    DESCRIPTION:
            change the variable value by function
    CMD:    g++ problem5_1.cpp -o problem5_1.out && ./problem5_1.out
*/
#include <iostream>

void print_value(int *a);
void change_value(int *a);

int main(int argc, char *argv[])
{
    int value = 5;
    
    print_value(&value);
    
    change_value(&value);
    std::cout << "After change the value by function, the new value is "
              << value
              << std::endl;
    
    return 0;
}

void print_value(int *a)
{
    std::cout << "The value of the integer is " 
              << *a
              << std::endl;
}

void change_value(int *a)
{
    *a = 1;
}
