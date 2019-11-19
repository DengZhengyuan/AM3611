//
// Created by Zhengyuan Deng on 2019/11/16.
//

#include <fstream>
#include "AbstractOdeSolver.h"
#include "RungeKutta.h"

RungeKuttaMethod::RungeKuttaMethod(double (*function)(double y, double t))
{
    m_function = function;
}

// specify the Right Hand Side function
double RungeKuttaMethod::RightHandSide(double y, double t) {
    double k1, k2, k3, k4;

    k1 = stepSize*m_function(y, t);
    k2 = stepSize*m_function(y+0.5*k1, t+0.5*stepSize);
    k3 = stepSize*m_function(y+0.5*k2, t+0.5*stepSize);
    k4 = stepSize*m_function(y+k3, t+stepSize);

    return (y + (1./6.)*(k1+2*k2+2*k3+k4));
}

// solve the ode and write the results in the file
void RungeKuttaMethod::SolveEquation() {
    double time, result;
    int size;
    size = (int) ((finalTime-initialTime)/stepSize +1);

    std::ofstream write_file("result_RK.dat");
    assert(write_file.is_open());

    write_file << initialTime
               << " "
               << initialValue
               << "\n";
    result = initialValue;
    int i = 1;
    do {
        time = initialTime + i*stepSize;
        result = RightHandSide(result, time);
        write_file << time
                   << " "
                   << result
                   << "\n";
        i++;
    } while (i < size);

    write_file.close();
}
