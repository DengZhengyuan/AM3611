//
// Created by Zhengyuan Deng on 2019/11/21.
//

#include "Quadrature.h"

Quadrature::Quadrature(double a, double b, int N) {
    m_a = a;
    m_b = b;
    m_N = N;
    h = (m_b - m_a)/m_N;
    vec_f = new double [N+1];
    vec_f2 = new double [N+1];
}

Quadrature::~Quadrature() {
    delete[] vec_f;
}

double &Quadrature::operator[](int index) {
    return vec_f[index];
}

double Quadrature::sum(int size, const double *vec) {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += vec[i];
    }
    return result;
}
