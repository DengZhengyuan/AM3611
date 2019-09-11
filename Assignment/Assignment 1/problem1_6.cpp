/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: problem 1.6
    DESCRIPTION: 
            calculate the average value of an array
    CMD:    g++ problem1_6.cpp -o problem1_6.out && ./problem1_6.out
*/

#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    double data[5] = {27., 54., 46., 37., 40.},
           average;

    average = (data[0] + data[1] + data[2] + data[3] + data[4]) / 5;

    std::cout << "The average value of data is "
              << average
              << std::endl;

    return 0;
}