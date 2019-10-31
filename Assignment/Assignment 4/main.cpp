/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.1 and 6.2
    DESCRIPTION:
            main function test file
    CMD:    
            g++ -Wall -O -c ComplexNumber.cpp && g++ -Wall -O -c matrix.cpp && g++ -Wall -lm -O -o main.out main.cpp ComplexNumber.o matrix.o && ./main.out
*/

#include <iostream>
#include "ComplexNumber.h"
#include "matrix.h"

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */

int main(int argc, char * argv[])
{
    /*--------------- Test Class ComplexNumber --------------*/
    ComplexNumber z1(1., 2.);
    std::cout << "Set a complex number "
              << z1
              << ". \n";

    std::cout << "\n6.1 (a). \nThe real part is "
              << z1.GetRealPart()
              << ". \n"
              << "The imaginary part is "
              << z1.GetImaginaryPart()
              << ". \n";

    std::cout << "\n6.1 (b). \nThe real part is "
              << RealPart(z1)
              << ". \n"
              << "The imaginary part is "
              << ImaginaryPart(z1)
              << ". \n";

    ComplexNumber z2(z1);
    std::cout << "\n6.1 (c). \nCopy z1 as z2: "
              << z2
              << ". \n";

    ComplexNumber z3(1.);
    std::cout << "\n6.1 (d). \nConvert real number '1.' into complex form: "
              << z3
              << ". \n";

    std::cout << "\n6.1 (e). \nCalculate the conjugate by const method: "
              << z1.CalculateConjugate()
              << ". \n";

    z1.SetToConjugate();
    std::cout << "\n6.1 (f). \nCalculate the conjugate with void return: "
              << z1
              << ". \n";
    
    /*--------------- Test Class matrix --------------*/
    matrix mat_A;
    std::cout << "\n6.2 (a). \n"
              << "Initializes all entries of the matrix to zero: \n";
    mat_A.print_matrix();

    matrix mat_B(1,2,3,4);
    std::cout << "\n6.2 (e). \n"
              << "The matrix mat_B specified with "
                 "elements of '1 2 3 4' are generated: \n";
    mat_B.print_matrix();

    matrix mat_B_copy(mat_B);
    std::cout << "\n6.2 (d). \n"
              << "The mat_B_copy is copied from mat_B: \n";
    mat_B_copy.print_matrix();

    std::cout << "\n6.2 (f). \n"
              << "The determinant of mat_B is: "
              << mat_B.determinant()
              << ". \n";

    std::cout << "\n6.2 (g). \n"
              << "The inverse of mat_B is: \n";
    mat_B.inverse().print_matrix();

    matrix mat_C;
    mat_C = mat_B;
    std::cout << "\n6.2 (h). \n"
              << "Let mat_C '=' mat_B: \n";
    mat_C.print_matrix();

    std::cout << "\n6.2 (i). \n"
              << "Test the unary '-' operator: \n";
    (-mat_B).print_matrix();

    std::cout << "\n6.2 (j). \n"
              << "Test the binary '+' operator (mat_B+mat_C): \n";
    (mat_B+mat_C).print_matrix();

    std::cout << "\n6.2 (j). \n"
              << "Test the binary '-' operator (mat_B-mat_C): \n";
    (mat_B-mat_C).print_matrix();

    std::cout << "\n6.2 (k). \n"
              << "Test the binary '*' operator (mat_B*mat_C): \n";
    (mat_B*mat_C).print_matrix();

    std::cout << "\n6.2 (l). \n"
              << "Test the binary '*' operator (3.*mat_C): \n";
    (3.*mat_C).print_matrix();


    return 0;
}
