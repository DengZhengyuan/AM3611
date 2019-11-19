//
// Created by Zhengyuan Deng on 2019/11/16.
//

#include "AbstractOdeSolver.h"

// set the step size of the solver
void AbstractOdeSolver::SetStepSize(double h) {
    stepSize = h;
}
// set the initial and final time
void AbstractOdeSolver::SetTimeInterval(double t0, double t1) {
    initialTime = t0;
    finalTime = t1;
}
// set the initial value
void AbstractOdeSolver::SetInitialValue(double y0) {
    initialValue = y0;
}
