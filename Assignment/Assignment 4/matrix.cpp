/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.2
    DESCRIPTION:
            class matrix
            the source code file
*/

#include "matrix.h"
#include <cassert>

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

// copy constructor
matrix::matrix(const matrix &other_matrix) {
    mat = new double* [2];
    mat[0] = new double [2];
    mat[1] = new double [2];
    mat[0][0] = other_matrix.mat[0][0];
    mat[0][1] = other_matrix.mat[0][1];
    mat[1][0] = other_matrix.mat[1][0];
    mat[1][1] = other_matrix.mat[1][1];
}

// method for calculation of determinant
double matrix::determinant() const {
    return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
}

// method for giving the inverse matrix
matrix matrix::inverse() const {
    double det = determinant();
    assert(det != 0);
    return matrix((1/det)*mat[1][1],-(1/det)*mat[0][1],
                  -(1/det)*mat[1][0],(1/det)*mat[0][0]);
}

// overload the '=' operator
matrix &matrix::operator=(const matrix &A) {
    mat[0][0] = A.mat[0][0];
    mat[0][1] = A.mat[0][1];
    mat[1][0] = A.mat[1][0];
    mat[1][1] = A.mat[1][1];
    return *this;
}

// overload the unary '-' operator
matrix matrix::operator-() const {
    matrix A;
    A.mat[0][0] = -mat[0][0];
    A.mat[0][1] = -mat[0][1];
    A.mat[1][0] = -mat[1][0];
    A.mat[1][1] = -mat[1][1];
    return A;
}

// overload the binary '+' operator
matrix operator+(const matrix &B, const matrix &C) {
    matrix A;
    A.mat[0][0] = B.mat[0][0] + C.mat[0][0];
    A.mat[0][1] = B.mat[0][1] + C.mat[0][1];
    A.mat[1][0] = B.mat[1][0] + C.mat[1][0];
    A.mat[1][1] = B.mat[1][1] + C.mat[1][1];
    return A;
}

// overload the binary '-' operator
matrix operator-(const matrix &B, const matrix &C) {
    matrix A;
    A.mat[0][0] = B.mat[0][0] - C.mat[0][0];
    A.mat[0][1] = B.mat[0][1] - C.mat[0][1];
    A.mat[1][0] = B.mat[1][0] - C.mat[1][0];
    A.mat[1][1] = B.mat[1][1] - C.mat[1][1];
    return A;
}

// overload the binary '*' operator
matrix operator*(const matrix &B, const matrix &C) {
    matrix A;
    double sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                sum += B.mat[i][k] * C.mat[k][j];
            }
            A.mat[i][j] = sum;
            sum = 0;
        }
    }
    return A;
}

// overload the binary '*' operator
matrix operator*(double s, const matrix &B) {
    matrix A;
    A.mat[0][0] = s*B.mat[0][0];
    A.mat[0][1] = s*B.mat[0][1];
    A.mat[1][0] = s*B.mat[1][0];
    A.mat[1][1] = s*B.mat[1][1];
    return A;
}
