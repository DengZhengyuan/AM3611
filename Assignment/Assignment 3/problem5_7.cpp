/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 13, 2019
    PROB #: problem 5.7
    DESCRIPTION:
            handle the pointers for matrix
    CMD:    g++ problem5_7.cpp -o problem5_7.out && ./problem5_7.out
*/

#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>

double p_norm(double *vector, int size, double p = 2);

int main(int argc, char const *argv[])
{
    std::ifstream read_file("value_p_norm.dat");
    assert(read_file.is_open());
    double *A;
    A = new double [1];
    int length_of_data = 0;
    while (!read_file.eof()) {
        read_file >> A[length_of_data];
        if (!read_file.fail())
        {
            length_of_data++;
        }
    }

    std::cout << "The 2-norm is "
              << p_norm(A, length_of_data)
              << std::endl;

    std::cout << "The 3-norm is "
              << p_norm(A, length_of_data,3)
              << std::endl;
    read_file.close();
    delete[] A;

    return 0;
}


double p_norm(double *vector, int size, double p) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(abs(vector[i]), p);
    }
    return pow(sum, 1/p);
}