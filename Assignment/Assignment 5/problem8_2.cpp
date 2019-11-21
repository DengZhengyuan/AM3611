/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Nov. 20, 2019
    PROB #: problem 8.2
    DESCRIPTION:
            template to get absolute value
    CMD:    g++ problem8_2.cpp -o problem8_2.out && ./problem8_2.out
*/

#include <iostream>

template<class T> T GetAbsoluteValue(T number);

int main(int argc, char* argv[])
{
    std::cout << GetAbsoluteValue<int>(-5) << std::endl;
    std::cout << GetAbsoluteValue<double>(1.225) << std::endl;

    return 0;
}

template<class T> T GetAbsoluteValue(T number)
{
    T result;
    if (number >= 0) {
        result = number;
    }
    else {
        result = -number;
    }
    return result;
}