//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_MIDPOINT_H
#define QUADRATURE_MIDPOINT_H


#include "Quadrature.h"

class Midpoint : public Quadrature {
public:
    explicit Midpoint(double a, double b, int N);
    void fi_values(double (*function)(double x)) override;
    double integral();
};


#endif //QUADRATURE_MIDPOINT_H
