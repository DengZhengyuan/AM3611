/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.2
    DESCRIPTION:
            class matrix
            header file
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
    matrix(const matrix& other_matrix);
    double determinant() const;
    matrix inverse() const;
    matrix& operator=(const matrix& mat);
    matrix operator-() const;
    friend matrix operator+(const matrix& B, const matrix& C);
    friend matrix operator-(const matrix& B, const matrix& C);
    friend matrix operator*(const matrix& B, const matrix& C);
    friend matrix operator*(double s, const matrix &B);
};


#endif //TEST_BY_CLION_2_MATRIX_H
