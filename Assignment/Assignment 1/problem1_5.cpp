/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: problem 1.5
    DESCRIPTION: 
            input the given name and family name
            print out the full name
    CMD:    g++ problem1_5.cpp -o problem1_5 && ./problem1_5
*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // define the 
    std::string given_name,
                family_name; 
    std::cout << "Please type your given name and press ENTER. \n"; 
    std::cin >> given_name; 
    std::cout << "Please type your family name and press ENTER. \n"; 
    std::cin >> family_name;
    
    std::cout << given_name << " " << family_name << std::endl;    

    return 0;
}