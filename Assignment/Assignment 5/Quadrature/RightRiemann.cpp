//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "RightRiemann.h"

RightRiemann::RightRiemann(double a, double b, int N) : Quadrature(a, b, N) {}

void RightRiemann::fi_values(double (*function)(double)) {
    for (int i = 0; i < m_N; i++) {
        vec_f[i] = function(m_a + (i+1)*h);
    }
}

double RightRiemann::integral() {
    return h*sum(m_N, vec_f);
}
