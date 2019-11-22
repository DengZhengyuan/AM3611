//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "Midpoint.h"

Midpoint::Midpoint(double a, double b, int N) : Quadrature(a, b, N) {}

void Midpoint::fi_values(double (*function)(double)) {
    for (int i = 0; i < m_N; i++) {
        vec_f[i] = function(
                0.5*((m_a + i*h)+(m_a + (i+1)*h))
                );
    }
}

double Midpoint::integral() {
    return h*sum(m_N, vec_f);
}
