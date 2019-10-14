/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 10, 2019
    PROB #: problem 5.4
    DESCRIPTION: 
            test the if statement
    CMD:    g++ problem5_4.cpp -o problem5_4.out && ./problem5_4.out
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <fstream>

double get_mean(int length, double *data);
double get_standard_deviation(int length, double *data);

int main(int argc, char const *argv[])
{
    double *data;
    data = new double[1000]; 
    int length = 1000; 

    std::ifstream read_file("randValues.dat");
    assert(read_file.is_open()); 
    for (int i = 0; i < length; i++)
    {
        read_file >> data[i];
    }
    read_file.close();

    std::cout << "The standard deviation is "
              << get_standard_deviation(length, data)
              << std::endl;

    delete[] data; 

    return 0;
}

double get_mean(int length, double *data)
{
    double sum = 0,
           mean = 0; 
    for (int i = 0; i < length; i++)
    {
        sum += data[i];
    }
    mean = sum / length;
    return mean;
}

double get_standard_deviation(int length, double *data)
{
    double sigma = 0,
           mean = get_mean(length, data),
           sum = 0; 
    for (int i = 0; i < length; i++)
    {
        sum += pow(data[i] - mean, 2); 
    }
    sigma = sqrt(sum/(length-1));
    return sigma; 
}