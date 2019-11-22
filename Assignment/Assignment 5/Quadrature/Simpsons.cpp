//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "Simpsons.h"

Simpsons::Simpsons(double a, double b, int N) : Quadrature(a, b, N) {

}

void Simpsons::fi_values(double (*function)(double)) {
    fa = function(m_a);
    fb = function(m_b);

    // number of elements: N/2-1
    for (int i = 0; i < (m_N/2-1); i++) {
        vec_f[i] = function(m_a + 2*(i+1)*h);
    }

    // number of elements: N/2
    for (int i = 0; i < (m_N/2); i++) {
        vec_f2[i] = function(m_a + (2*(i+1)-1)*h);
    }
}

double Simpsons::integral() {
    return (h/3)*(
            fa + fb
            + 2*sum((m_N/2-1), vec_f)
            + 4*sum((m_N/2), vec_f));
}
