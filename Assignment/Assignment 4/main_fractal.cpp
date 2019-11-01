#include <iostream>
#include "ComplexNumber.h"
#include "Fractal.h"

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */

int main(int argc, char * argv[])
{
    Fractal test(300,300);
    ComplexNumber c1(-0.8, 0.156);

    test.Julia_set(c1);
//    test.Mandalbrot_set(c1);
    test.print_fractal();

    return 0;
}
