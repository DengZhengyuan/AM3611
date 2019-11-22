//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "LeftRiemann.h"
#include <iostream>

LeftRiemann::LeftRiemann(double a, double b, int N) : Quadrature(a, b, N) {}

void LeftRiemann::fi_values(double (*function)(double)) {
    for (int i = 0; i < m_N; i++) {
        vec_f[i] = function(m_a + i*h);
    }
}

double LeftRiemann::integral() {
    return h*sum(m_N, vec_f);
}
