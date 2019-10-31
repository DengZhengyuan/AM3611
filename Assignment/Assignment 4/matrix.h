/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.2
    DESCRIPTION:
            
    CMD:    
            g++ -Wall -O -c matrix.cpp && g++ -Wall -lm -O -o main.out main.cpp matrix.o && ./main.out
*/

#ifndef TEST_BY_CLION_2_MATRIX_H
#define TEST_BY_CLION_2_MATRIX_H

#include <iostream>

class matrix {
private:
    double** mat;
public:
    explicit matrix(double a00 = 0.,
                    double a01 = 0.,
                    double a10 = 0.,
                    double a11 = 0.);
    ~matrix();
    void print_matrix();


};


#endif //TEST_BY_CLION_2_MATRIX_H
