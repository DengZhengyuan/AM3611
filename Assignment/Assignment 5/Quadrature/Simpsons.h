//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_SIMPSONS_H
#define QUADRATURE_SIMPSONS_H


#include "Quadrature.h"

class Simpsons : public Quadrature {
private:
    double fa{};
    double fb{};
public:
    explicit Simpsons(double a, double b, int N);
    void fi_values(double (*function)(double x)) override;
    double integral();
};


#endif //QUADRATURE_SIMPSONS_H
