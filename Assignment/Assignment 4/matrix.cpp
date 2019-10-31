/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.2
    DESCRIPTION:
            
    CMD:    
            g++ -Wall -O -c matrix.cpp && g++ -Wall -lm -O -o main.out main.cpp matrix.o && ./main.out
*/

#include "matrix.h"
    
// constructor
// initialize all elements as zero by default
matrix::matrix(double a00, double a01, double a10, double a11) {
    mat = new double* [2];
    mat[0] = new double [2];
    mat[1] = new double [2];
    mat[0][0] = a00;
    mat[0][1] = a01;
    mat[1][0] = a10;
    mat[1][1] = a11;
}
// destructor
matrix::~matrix() {
    delete[] mat[0];
    delete[] mat[1];
    delete[] mat;
}

// print the matrix
void matrix::print_matrix() {
    std::cout << mat[0][0] << "\t"
              << mat[0][1] << "\n"
              << mat[1][0] << "\t"
              << mat[1][1] << "\n";
}
