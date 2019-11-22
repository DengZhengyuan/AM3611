//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_RIGHTRIEMANN_H
#define QUADRATURE_RIGHTRIEMANN_H


#include "Quadrature.h"

class RightRiemann : public Quadrature
{
public:
    explicit RightRiemann(double a, double b, int N);
    void fi_values(double (*function)(double x)) override;
    double integral();
};


#endif //QUADRATURE_RIGHTRIEMANN_H
