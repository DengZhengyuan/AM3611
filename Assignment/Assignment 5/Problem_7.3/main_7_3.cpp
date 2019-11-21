/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Nov. 18, 2019
    PROB #: Problem 7.3
    DESCRIPTION:
            add Euler method and Runge Kutta method into AbstractOdeSover to solve the ODE
    CMD:    
            g++ -Wall -O -c AbstractOdeSolver.cpp && g++ -Wall -O -c EulerMethod.cpp && g++ -Wall -O -c RungeKutta.cpp && g++ -Wall -lm -O -o main_7_3.out main_7_3.cpp AbstractOdeSolver.o EulerMethod.o RungeKutta.o && ./main_7_3.out
*/

#include <iostream>
#include "EulerMethod.h"
#include "AbstractOdeSolver.h"
#include "RungeKutta.h"

double input_function(double y, double t);


/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */
int main(int argc, char * argv[]) {

    EulerMethod sol_Euler(input_function);
    sol_Euler.SetInitialValue(2);
    sol_Euler.SetStepSize(0.01);
    sol_Euler.SetTimeInterval(0, 1);
    sol_Euler.SolveEquation();

    RungeKuttaMethod sol_RK(input_function);
    sol_RK.SetInitialValue(2);
    sol_RK.SetStepSize(0.01);
    sol_RK.SetTimeInterval(0, 1);
    sol_RK.SolveEquation();

    return 0;
}


double input_function(double y, double t) {
    return 1+t;
}