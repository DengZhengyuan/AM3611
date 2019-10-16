/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 13, 2019
    PROB #: Assignment 3 part B
    DESCRIPTION:
            finite difference method
    CMD:    g++ FiniteDifference.cpp -o FiniteDifference.out && ./FiniteDifference.out
*/

#include <iostream>
#include <cassert>
#include <fstream>
#include <cmath>

// create a matrix by the size of (row x column)
double** create_a_matrix(int row, int column);

// create a square matrix by the size of (row x row)
double** create_a_matrix(int row);

double** tri_banded_matrix(int size, double value_a, double value_b);

// release the memory of a matrix
void release_the_matrix(double **mat);

// console out a square matrix or a vector
void print_m_v(int size, double **mat);
void print_m_v(int size, double *vec);

// decompose a symmetric positive definite matrix by Cholesky
double** Cholesky_decomposition(int size, double **A);

// forward substitution
double* forward_substitution(int size, double **Cholesky, double *b);

// backward substitution
double* backward_substitution(int size, double **Cholesky, double *b);

// package the Cholesky_decomposition, forward substitution, and
// backward substitution.
// And gives the final solutions of a linear system
double* solve_linear_by_Cholesky(int size, double **A, double *b);

int main(int argc, char const *argv[])
{
    const double PI = atan(1.0)*4;

    int nodes = 101;
    double time_steps = 50;
    double time = 2;
    double h = 1./(nodes-1.);
    double k = time / (time_steps-1);
    double alpha = 1 / pow(PI, 2);
    double a = - (alpha*k) / pow(h, 2);
    double b = (2*alpha*k)/pow(h, 2) + 1;

    double **A;
    A = tri_banded_matrix(nodes, a, b);

    double* initial_U;
    initial_U = new double [nodes];
    for (int i = 0; i < nodes; i++)
    {
        if (i == 0 || i == (nodes-1)) {
            initial_U[i] = 0;
        }
        else {
            initial_U[i] = (1 / pow(PI, 2)) * sin(PI * i * h);
        }
    }
    // write the initial U to the file
    std::ofstream write_initial("matrix.dat");
    for (int i = 0; i < nodes; i++) {
        write_initial << initial_U[i] << " ";
    }
    write_initial << "\n";
    write_initial.close();

    double *matrix_U1, *matrix_U2;
    matrix_U1 = initial_U;

    std::ofstream write_file("matrix.dat", std::ios::app);
    for (int j = 0; j < time_steps; j++) {
        matrix_U2 = solve_linear_by_Cholesky(nodes, A, matrix_U1);
        // write the U to the file
        for (int i = 0; i < nodes; i++) {
            write_file << matrix_U2[i] << " ";
        }
        write_file << "\n";
        write_file.flush();
        matrix_U1 = matrix_U2;
    }
    write_file.close();

    delete[] initial_U;
    delete[] matrix_U1;
    release_the_matrix(A);

    return 0;
}

double** create_a_matrix(int row, int column) {
    double **mat;
    mat = new double *[row];
    // contiguous array
    mat[0] = new double [row*column];
    for (int i = 1; i < row; i++) {
        mat[i] = mat[i-1] + column;
    }
    return mat;
}
double** create_a_matrix(int row) {
    double **mat;
    mat = new double *[row];
    // contiguous array
    mat[0] = new double [row*row];
    for (int i = 1; i < row; i++) {
        mat[i] = mat[i-1] + row;
    }
    return mat;
}

double** tri_banded_matrix(int size, double value_a, double value_b)
{
    double **mat;
    mat = create_a_matrix(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j) {
                mat[i][j] = value_b;
            }
            else if (i == (j+1) || (i+1) == j) {
                mat[i][j] = value_a;
            }
        }
    }
    return mat;
}

void release_the_matrix(double **mat) {
    delete[] mat[0];
    delete[] mat;
}

void print_m_v(int size, double **mat)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
void print_m_v(int size, double *vec)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << vec[i] << "\t";
    }
    std::cout << "\n";
}

double** Cholesky_decomposition(int size, double **A)
{
    double **L;
    L = create_a_matrix(size);

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (i == j)
            {
                double sum = 0;
                for (int k = 0; k < j; k++)
                {
                    sum += pow(L[j][k], 2);
                }
                L[i][j] = sqrt(A[j][j] - sum);
            }
            else if (i > j)
            {
                double sum = 0;
                for (int k = 0; k < j; k++)
                {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (1/L[j][j]) * (A[i][j] - sum);
            }
            else
            {
                L[i][j] = 0;
            }
        }
    }

    return L;
}

double* forward_substitution(int size, double **Cholesky, double *b)
{
    double *x;
    x = new double [size];
    for (int i = 0; i < size; i++)
    {
        if (i == 0) {
            x[i] = b[i] / Cholesky[i][i];
//            x[i] = 0;
        }
        else {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += Cholesky[i][j] * x[j];
            }
            x[i] = (b[i] - sum) / Cholesky[i][i];
        }
    }

    return x;
}

double* backward_substitution(int size, double **Cholesky, double *b)
{
    double *x;
    x = new double [size];
    for (int i = (size-1); i >= 0; i--)
    {
        if (i == (size - 1)) {
            x[i] = b[i] / Cholesky[i][i];
//            x[i] = 0;
        }
        else {
            double sum = 0;
            for (int j = (size-1); j > i; j--)
            {
                sum += Cholesky[j][i] * x[j];
            }
            x[i] = (b[i] - sum) / Cholesky[i][i];
        }
    }
    return x;
}

double* solve_linear_by_Cholesky(int size, double **A, double *b) {
    double **ch, *fs, *bs;
    ch = Cholesky_decomposition(size, A);
    fs = forward_substitution(size, ch, b);
    bs = backward_substitution(size, ch, fs);

    release_the_matrix(ch);
    delete[] fs;
    return bs;
}
