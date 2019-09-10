/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: Assignment 1 Part B
    DESCRIPTION: 
            calculate the average value of an array
    CMD:    g++ GramSchmidt.cpp -o GramSchmidt && ./GramSchmidt
*/

#include <iostream>
#include <cmath>

// define the dot production
double dot_production(int size, double *vec_1, double *vec_2);

// define the Euclidean norm
double Euclidean_norm(double *array);

// define the projection of vec_a to vec_u
double* projection(int size, double *vec_u, double *vec_a);

/* ---------------------------------------------- */

int main(int argc, char *argv[])
{   
    int size = 3; 
    double *u = new double [size], 
           *a = new double [size]; 

    double *result = new double [size]; 

    u[0] = 1; u[1] = 2; u[2] = 3;
    a[0] = 4; a[1] = 5; a[2] = 6;

    result = projection(size, u, a);

    for (int i = 0; i < size; i++) {
        std::cout << result[i] << std::endl;
    }

    delete[] u;
    delete[] a;
    delete[] result;

    return 0;
}

/* ---------------------------------------------- */

double dot_production(int size, double *vec_1, double *vec_2)
{
    double result;
    for (int i = 0; i < size; i++) {
        result += vec_1[i] * vec_2[i];
    }
    return result;
}

double Euclidean_norm(double *array)
{
    double result,
           sum;
    for (int i = 0; i < sizeof(array); i++) {
        sum += pow(array[i], 2);
    }
    result = sqrt(sum);
    return result;
}

double* projection(int size, double *vec_u, double *vec_a)
{
    double *vec; 
    vec = new double [size];

    double coefficient;

    coefficient = dot_production(size, vec_u, vec_a) /
                  dot_production(size, vec_u, vec_u); 

    for (int i = 0; i < size; i++) {
        vec[i] = vec_u[i] * coefficient;
    }

    return vec;
}