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
double dot_production(double *array_1, double *array_2)
{
    double result;
    if (sizeof(array_1) == sizeof(array_2))
    {
        for (int i = 0; i < sizeof(array_1); i++)
            result += array_1[i] * array_2[i];
    }
    else
    {
        std::cerr << "ERROR: the sizes of vectors x and y are different. ";
    }
    return result;
}

// define the function to calculate the Euclidean norm
double Euclidean_norm(double *array)
{
    double result,
        sum;
    for (int i = 0; i < sizeof(array); i++)
        sum += pow(array[i], 2);
    result = sqrt(sum);
    return result;
}

int main(int argc, char *argv[])
{
    // define the vectors x and y
    double array_x[4] = {3.14, 2.72, 1.62, 0.};
    double array_y[4] = {pow(2, 8) - 1,
                         (sqrt(13) + 3) / (2),
                         log(2),
                         sin(M_PI / 2)};

    // print out the result of dot production
    std::cout << "The dot production of vectors x and y is "
              << dot_production(array_x, array_y)
              << ". "
              << std::endl;
    // print out the result of Euclidean norm
    std::cout << "The Euclidean norm of vector x is "
              << Euclidean_norm(array_x)
              << ". "
              << std::endl;

    return 0;
}