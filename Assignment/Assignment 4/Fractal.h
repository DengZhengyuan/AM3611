//
// Created by Zhengyuan Deng on 2019/10/31.
//

#ifndef TEST_BY_CLION_2_FRACTAL_H
#define TEST_BY_CLION_2_FRACTAL_H

#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

class Fractal {
private:
    double **matrix;
    int m_nrows{};
    int m_ncols{};
    double m_minReal{};
    double m_maxReal{};
    double m_minImag{};
    double m_maxImag{};
public:
    explicit Fractal(int nrows = 80,
                     int ncols = 80,
                     double minReal = -2.,
                     double maxReal = 2.,
                     double minImag = -2.,
                     double maxImag = 2.);
    ~Fractal();
    void reset_real_domain(double minReal, double maxReal);
    void reset_imag_domain(double minImag, double maxImag);
    double distance_real_axis();
    double distance_imag_axis();
    static int iterate_times(ComplexNumber z, const ComplexNumber& C, int max_iteration);
    void Julia_set(const ComplexNumber& c, int max_iter = 80);
    void print_fractal();
//    void Mandalbrot_set(const ComplexNumber &c, int max_iter = 80);
};


#endif //TEST_BY_CLION_2_FRACTAL_H
