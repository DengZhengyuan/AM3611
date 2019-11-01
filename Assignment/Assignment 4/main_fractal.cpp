/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: Assignment 4 Part B
    DESCRIPTION:
            main function test file
    CMD:    
            g++ -Wall -O -c ComplexNumber.cpp && g++ -Wall -O -c Fractal.cpp && g++ -Wall -lm -O -o main_fractal.out main_fractal.cpp ComplexNumber.o Fractal.o && ./main_fractal.out
*/

#include <iostream>
#include "ComplexNumber.h"
#include "Fractal.h"

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */

int main(int argc, char * argv[])
{
    int resolution = 800;

    /*--------- Test Julia set ---------*/
    Fractal test_julia(resolution, resolution);
    ComplexNumber c1(-0.8, 0.156);
    test_julia.Julia_set(c1);
//    test_julia.print_fractal();
    test_julia.write_file_fractal("julia_1.dat");
    // c = 0.285 + 0.01i
    ComplexNumber c2(0.285, 0.01);
    test_julia.Julia_set(c2);
    test_julia.write_file_fractal("julia_2.dat");
    // c = -0.70176 - 0.3842i
    ComplexNumber c3(-0.70176, -0.3842);
    test_julia.Julia_set(c3);
    test_julia.write_file_fractal("julia_3.dat");


    /*--------- Test Mandalbrot set ---------*/
    Fractal test_mandalbrot(resolution*0.75, resolution);
    test_mandalbrot.reset_real_domain(-2,2);
    test_mandalbrot.reset_imag_domain(-1.5,1.5);
    test_mandalbrot.Mandalbrot_set();
//    test_mandalbrot.print_fractal();
    test_mandalbrot.write_file_fractal("man_1.dat");
    // domain: {-1 + 0.0 i, -0.60 + 0.4 i}
    Fractal test_mandalbrot_2(resolution, resolution);
    test_mandalbrot_2.reset_real_domain(-1,-0.6);
    test_mandalbrot_2.reset_imag_domain(0,.4);
    test_mandalbrot_2.Mandalbrot_set();
//    test_mandalbrot.print_fractal();
    test_mandalbrot_2.write_file_fractal("man_2.dat");
    // domain: {-0.74 + 0.31 i, -0.66 + 0.39 i}
    test_mandalbrot_2.reset_real_domain(-0.74,-.66);
    test_mandalbrot_2.reset_imag_domain(0.31,.39);
    test_mandalbrot_2.Mandalbrot_set();
//    test_mandalbrot.print_fractal();
    test_mandalbrot_2.write_file_fractal("man_3.dat");

    return 0;
}
