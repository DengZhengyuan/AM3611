//
// Created by Zhengyuan Deng on 2019/11/16.
//

#ifndef AM3611_ASSIGNMENT_5_RUNGEKUTTA_H
#define AM3611_ASSIGNMENT_5_RUNGEKUTTA_H

#include <iostream>
#include "AbstractOdeSolver.h"
#include "RungeKutta.h"

class RungeKuttaMethod : public AbstractOdeSolver
{
private:
    double (*m_function)(double y, double t);
public:
    explicit RungeKuttaMethod(double (*function)(double y, double t));
    double RightHandSide(double y, double t);
    void SolveEquation();
};


#endif //AM3611_ASSIGNMENT_5_RUNGEKUTTA_H
