/*
CMD:    g++ test.cpp -o test.out && ./test.out
*/

#include <iostream>
#include <cmath>

int main(int argc, char const *argv[])
{
    double *data[1000]; 
    std::cout << (sizeof(data) / sizeof(data[0]))
              << std::endl;
    // delete[] data; 
    return 0; 
}