//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_LEFTRIEMANN_H
#define QUADRATURE_LEFTRIEMANN_H


#include "Quadrature.h"

class LeftRiemann : public Quadrature
{
public:
    explicit LeftRiemann(double a, double b, int N);
    void fi_values(double (*function)(double x)) override;
    double integral();
};


#endif //QUADRATURE_LEFTRIEMANN_H
