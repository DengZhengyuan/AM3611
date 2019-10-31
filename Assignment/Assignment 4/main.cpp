/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.1 and 6.2
    DESCRIPTION:
            test main function file
    CMD:    
            g++ -Wall -O -c ComplexNumber.cpp && g++ -Wall -lm -O -o main.out main.cpp ComplexNumber.o && ./main.out
*/

#include <iostream>
#include "ComplexNumber.h"

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */

int main(int argc, char * argv[])
{
    ComplexNumber z1(1., 2.);
    std::cout << "Set a complex number "
              << z1
              << ". \n";

    std::cout << "6.1 (a). \nThe real part is "
              << z1.GetRealPart()
              << ". \n"
              << "The imaginary part is "
              << z1.GetImaginaryPart()
              << ". \n";

    std::cout << "6.1 (b). \nThe real part is "
              << RealPart(z1)
              << ". \n"
              << "The imaginary part is "
              << ImaginaryPart(z1)
              << ". \n";

    ComplexNumber z2(z1);
    std::cout << "6.1 (c). \nCopy z1 as z2: "
              << z2
              << ". \n";

    ComplexNumber z3(1.);
    std::cout << "6.1 (d). \nConvert real number '1.' into complex form: "
              << z3
              << ". \n";

    std::cout << "6.1 (e). \nCalculate the conjugate by const method: "
              << z1.CalculateConjugate()
              << ". \n";

    z1.SetToConjugate();
    std::cout << "6.1 (f). \nCalculate the conjugate with void return: "
              << z1
              << ". \n";

    return 0;
}

