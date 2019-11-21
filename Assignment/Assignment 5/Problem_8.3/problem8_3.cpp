/*
    g++ -Wall -O -c list.cpp && g++ -Wall -lm -O -o problem8_3.out problem8_3.cpp List.o && ./problem8_3.out
*/

#include <iostream>
//#include "ComplexNumber.h"
#include "List.h"

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */
int main(int argc, char * argv[]) {
    List<double> test(3);
    test[0] = 1;
    test[1] = 2;
    test[2] = 3;

    std::cout << test.getLength()
              << "\n";

    return 0;
}
