//
// Created by Zhengyuan Deng on 2019/11/16.
//

#ifndef AM3611_ASSIGNMENT_5_EULERMETHOD_H
#define AM3611_ASSIGNMENT_5_EULERMETHOD_H
#include "AbstractOdeSolver.h"
#include "EulerMethod.h"
#include <fstream>

class EulerMethod : public AbstractOdeSolver
{
private:
    double (*m_function)(double y, double t);

public:
    explicit EulerMethod(double (*function)(double y, double t));
    double RightHandSide(double y, double t);
    void SolveEquation();
};


#endif //AM3611_ASSIGNMENT_5_EULERMETHOD_H
