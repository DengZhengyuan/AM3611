//
// Created by Zhengyuan Deng on 2019/11/21.
//

#ifndef QUADRATURE_QUADRATURE_H
#define QUADRATURE_QUADRATURE_H


class Quadrature {
protected:
    double m_a{};
    double m_b{};
    int m_N{};
    double h{};
    double* vec_f;
    double* vec_f2;

public:
    explicit Quadrature(double a, double b, int N);
    ~Quadrature();
    double &operator[](int index);
    virtual void fi_values(double (*function)(double x)) = 0;
    static double sum(int size, const double* vec);
};


#endif //QUADRATURE_QUADRATURE_H
