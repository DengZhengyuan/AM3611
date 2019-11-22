//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_TRAPEZOID_H
#define QUADRATURE_TRAPEZOID_H


#include "Quadrature.h"

class Trapezoid : public Quadrature {
private:
    double fa{};
    double fb{};
public:
    explicit Trapezoid(double a, double b, int N);
    void fi_values(double (*function)(double x)) override;
    double integral();
};


#endif //QUADRATURE_TRAPEZOID_H
