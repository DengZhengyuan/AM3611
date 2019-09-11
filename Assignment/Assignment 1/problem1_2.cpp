/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: problem 1.2
    DESCRIPTION: 
            enter two integers from the keyboard and then print 
            out the product of these integers.
    CMD:    g++ problem1_2.cpp -o problem1_2.out && ./problem1_2.out
*/

#include <iostream>

int main(int argc, char *arg[])
{
    // define the variables
    int integer_1,
        integer_2,
        result;

    // display prompting message
    std::cout << "Please input two integers and press ENTER. (for example: 2 3 ENTER) \n";

    // read two integers from the keyboard
    std::cin >> integer_1;
    std::cin >> integer_2;

    // calculation the production
    result = integer_1 * integer_2;

    // print out the result
    std::cout << "the production of "
              << integer_1
              << " and "
              << integer_2
              << " is "
              << result
              << ". "
              << std::endl;

    return 0;
}