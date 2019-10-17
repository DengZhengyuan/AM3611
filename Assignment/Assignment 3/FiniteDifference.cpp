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
#include <string>

// create a matrix by the size of (row x column)
double** create_a_matrix(int row, int column);
// create a square matrix by the size of (row x row)
double** create_a_matrix(int row);

// create a tri-diagonal banded matrix of 'a b a'
double** tri_banded_matrix(int size, double value_a, double value_b);

// release the memory of a matrix
void release_the_matrix(double **mat);

// console out a square matrix or a vector
void print_m_v(int row, int col, double **mat);
void print_m_v(int size, double *vec);

// decompose a symmetric positive definite matrix by Cholesky
double** Cholesky_decomposition(int size, double **A);

// forward substitution
double* forward_substitution(int size, double **Cholesky, const double *b);

// backward substitution
double* backward_substitution(int size, double **Cholesky, const double *b);

// package the Cholesky_decomposition, forward substitution, and
// backward substitution.
// And gives the final solutions of a linear system
double* solve_linear_by_Cholesky(int size, double **A, double *b);

void write_files(const std::string& name, double **mat, int row, int col);

/* --------------------------------------------------------------------------- */
/*                                main functions                               */
/* --------------------------------------------------------------------------- */

int main(int argc, char const *argv[])
{
    const double PI = atan(1.0)*4;

    int nodes = 101;
    int time_steps = 50;
    double time = 2;
    double h = 1./(nodes-1.);
    double k = time / (time_steps-1.);
    double alpha = 1 / pow(PI, 2);
    double a = - (alpha*k) / pow(h, 2);
    double b = (2*alpha*k)/pow(h, 2) + 1;

    double **A, **matrix;
    A = tri_banded_matrix((nodes-2), a, b);
    matrix = create_a_matrix((time_steps+1), (nodes-2));

    // initial conditions
    for (int i = 0; i < (nodes-2); i++) {
            matrix[0][i] = (1 / pow(PI, 2)) * sin(PI*(i+1)*h);
    }

    // calculation
    for (int i = 0; i < (time_steps+1); i++) {
        matrix[i+1] = solve_linear_by_Cholesky((nodes-2), A, matrix[i]);
    }

    double **final_results;
    final_results = create_a_matrix((time_steps+1), nodes);
    for (int i = 0; i < (time_steps + 1); i++) {
        for (int j = 0; j < nodes; j++) {
            if (j == 0 || j == (nodes-1)) {
                final_results[i][j] = 0;
            }
            else {
                final_results[i][j] = matrix[i][j-1];
            }
        }
    }
//    print_m_v(time_steps+1, nodes, final_results);


    // write the data to file
    write_files("test.dat", final_results, (time_steps+1), nodes);

    // release the memory
    release_the_matrix(A);
    release_the_matrix(matrix);
    release_the_matrix(final_results);
    return 0;
}

/* --------------------------------------------------------------------------- */
/*                               define functions                              */
/* --------------------------------------------------------------------------- */

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

void print_m_v(int row, int col, double **mat)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
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

double* forward_substitution(int size, double **Cholesky, const double *b)
{
    double *x;
    x = new double [size];
    for (int i = 0; i < size; i++)
    {
        if (i == 0) {
            x[i] = b[i] / Cholesky[i][i];
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

double* backward_substitution(int size, double **Cholesky, const double *b)
{
    double *x;
    x = new double [size];
    for (int i = (size-1); i >= 0; i--)
    {
        if (i == (size - 1)) {
            x[i] = b[i] / Cholesky[i][i];
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

void write_files(const std::string& name, double **mat, int row, int col) {
    std::ofstream write_file(name);
    assert(write_file.is_open());
    for (int j = 0; j < row; j++) {
        for (int i = 0; i < col; i++) {
            write_file << mat[j][i] << " ";
        }
        write_file << "\n";
//        write_file.flush();
    }
    write_file.close();
}
