#include <iostream>

int main(int argc, char *argv[])
{
    double *x;
    x = new double [10];  
    std::cout << x << "\n";
    std::cout << &x << "\n";
    delete[] x; 
    return 0;
}