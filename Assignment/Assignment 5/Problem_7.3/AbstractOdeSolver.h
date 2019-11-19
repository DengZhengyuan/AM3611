//
// Created by Zhengyuan Deng on 2019/11/16.
//

#ifndef AM3611_ASSIGNMENT_5_ABSTRACTODESOLVER_H
#define AM3611_ASSIGNMENT_5_ABSTRACTODESOLVER_H

#include <iostream>
#include "AbstractOdeSolver.h"

class AbstractOdeSolver {
protected:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;
public:
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    virtual double RightHandSide(double y, double t) = 0;
    virtual void SolveEquation() = 0;
};


#endif //AM3611_ASSIGNMENT_5_ABSTRACTODESOLVER_H
