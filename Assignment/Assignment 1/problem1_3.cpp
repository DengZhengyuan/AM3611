/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: problem 1.3
    DESCRIPTION: 
            calculate the dot production of two vectors, 
            calculate the Euclidean norm of vector
    CMD:    g++ problem1_3.cpp -o problem1_3 && ./problem1_3
*/

#include <iostream>
#include <cmath>

// define the function to calculate the dot production
double dot_production(int size, double *array_1, double *array_2);

// define the function to calculate the Euclidean norm
double Euclidean_norm(int size, double *array);

int main(int argc, char *argv[])
{
    // define the vectors x and y
    int size = 4; 
    double array_x[4] = {3.14, 2.72, 1.62, 0.};
    double array_y[4] = {pow(2, 8) - 1,
                            (sqrt(13) + 3) / (2),
                            log(2),
                            sin(M_PI / 2)};

    // print out the result of dot production
    std::cout << "The dot production of vectors x and y is "
              << dot_production(size, array_x, array_y)
              << ". "
              << std::endl;
    // print out the result of Euclidean norm
    std::cout << "The Euclidean norm of vector x is "
              << Euclidean_norm(size, array_x)
              << ". "
              << std::endl;
    std::cout << "The Euclidean norm of vector y is "
              << Euclidean_norm(size, array_y)
              << ". "
              << std::endl;

    return 0;
}

double dot_production(int size, double *array_1, double *array_2)
{
    double result = 0.;
    for (int i = 0; i < size; i++)
        result += array_1[i] * array_2[i];
    return result;
}

double Euclidean_norm(int size, double *array)
{
    double result = 0.,
           sum = 0.;
    for (int i = 0; i < size; i++)
        sum += pow(array[i], 2);
    result = sqrt(sum);
    return result;
}