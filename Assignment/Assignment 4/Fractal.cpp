/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: Assignment 4 Part B
    DESCRIPTION:
            class Fractal
            the source code file
*/

#include "Fractal.h"

// constructor
Fractal::Fractal(int nrows, int ncols,
                 double minReal, double maxReal,
                 double minImag, double maxImag) {
    // save the arguments in the class
    m_nrows = nrows;
    m_ncols = ncols;
    m_minReal = minReal;
    m_maxReal = maxReal;
    m_minImag = minImag;
    m_maxImag = maxImag;
    // create a matrix
    matrix = new double *[nrows];
    for (int i = 0; i < nrows; i++) {
        matrix[i] = new double[ncols];
    }
    std::cout << "***The matrix has been made.\n";
}

// destructor
Fractal::~Fractal() {
    for (int i = 0; i < m_nrows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    std::cout << "***The matrix has been deleted.\n";
}

// reset the real value domain
void Fractal::reset_real_domain(double minReal, double maxReal) {
    m_minReal = minReal;
    m_maxReal = maxReal;
}

// reset the imaginary value domain
void Fractal::reset_imag_domain(double minImag, double maxImag) {
    m_minImag = minImag;
    m_maxImag = maxImag;
}

double Fractal::distance_real_axis() {
    return (m_maxReal-m_minReal)/(m_ncols-1);
}

double Fractal::distance_imag_axis() {
    return (m_maxImag-m_minImag)/(m_nrows-1);
}

int Fractal::iterate_times(ComplexNumber z, const ComplexNumber& c, int max_iteration) {
    int i = 0;
    while (z.CalculateModulus() <= 2. && i < max_iteration) {
        z = z.CalculatePower(2) + c;
        i++;
    }
    return i;
}

void Fractal::Julia_set(const ComplexNumber& c, int max_iter) {
    double real_part = m_minReal;
    double imag_part = m_maxImag;

    for (int i = 0; i < m_nrows; i++) {
        for (int j = 0; j < m_ncols; j++) {
            ComplexNumber z(real_part, imag_part);
            matrix[i][j] = iterate_times(z, c, max_iter);
            real_part += distance_real_axis();
        }
        imag_part -= distance_imag_axis();
        real_part = m_minReal;
    }
}

void Fractal::Mandalbrot_set(int max_iter) {
    ComplexNumber z;
    double real_part = m_minReal;
    double imag_part = m_maxImag;
    for (int i = 0; i < m_nrows; i++) {
        for (int j = 0; j < m_ncols; j++) {
            ComplexNumber c(real_part, imag_part);
            matrix[i][j] = iterate_times(z, c, max_iter);
            real_part += distance_real_axis();
        }
        imag_part -= distance_imag_axis();
        real_part = m_minReal;
    }
}

void Fractal::print_fractal() {
    for (int i = 0; i < m_nrows; i++) {
        for (int j = 0; j < m_ncols; j++) {
            if (matrix[i][j] == 80) {
                std::cout << "X ";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }
}

void Fractal::write_file_fractal(const std::string& name) {
    std::ofstream write_file(name);
    assert(write_file.is_open());
    for (int j = 0; j < m_nrows; j++) {
        for (int i = 0; i < m_ncols; i++) {
            write_file << matrix[j][i] << " ";
        }
        write_file << "\n";
    }
    write_file.close();
}