//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "Trapezoid.h"

Trapezoid::Trapezoid(double a, double b, int N) : Quadrature(a, b, N) {}

void Trapezoid::fi_values(double (*function)(double)) {
    fa = function(m_a);
    fb = function(m_b);
    for (int i = 0; i < (m_N-1); i++) {
        vec_f[i] = function(m_a + (i+1)*h);
    }
}

double Trapezoid::integral() {
    return h*(fa/2 + fb/2 + sum(m_N-1, vec_f));
}
