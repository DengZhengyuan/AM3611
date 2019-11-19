//
// Created by Zhengyuan Deng on 2019/11/16.
//

#include "AbstractOdeSolver.h"
#include "EulerMethod.h"

EulerMethod::EulerMethod(double (*function)(double y, double t))
{
    m_function = function;
}

// specify the Right Hand Side function
double EulerMethod::RightHandSide(double y, double t) {
    return (y + stepSize*m_function(y, t));
}

// solve the ode and write the results in the file
void EulerMethod::SolveEquation() {
    double time, result;
    int size;
    size = (int) ((finalTime-initialTime)/stepSize +1);

    std::ofstream write_file("result_Euler.dat");
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