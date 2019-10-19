/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 10, 2019
    PROB #: problem 5.5
    DESCRIPTION:
            calculate the multiply of matrix
    CMD:    g++ problem5_5.cpp -o problem5_5.out && ./problem5_5.out
*/

#include <iostream>
#include <cassert>

// create a matrix by the size of row x column
double** create_a_matrix(int row, int column);

// release the memory of a matrix
void release_the_matrix(int row, double **mat);

// calculate the multiply of
// 1) matrix with matrix
double **Multiply(int mat_1_r, int mat_1_c, double **mat_1,
                  int mat_2_r, int mat_2_c, double **mat_2);
// 2) vector with matrix
double *Multiply(int vec_c, double const *vec,
                  int mat_r, int mat_c, double **mat);
// 3) matrix with vector
double *Multiply(int mat_r, int mat_c, double **mat,
                  int vec_r, double const *vec);
// 4) scalar with matrix
double **Multiply(double scalar,
                  int mat_r, int mat_c, double **mat);
// 5) matrix with scalar
double **Multiply(int mat_r, int mat_c, double **mat,
                  double scalar);
// _r and _c represent the row and the column, respectively
// mat and vec represent the matrix and vector, respectively

int main(int argc, char const *argv[]) {
    int chose;
    std::cout << "Which function do you want to test? "
              << "Calculating the multiply of \n"
              << "1) matrix with matrix;\n"
              << "2) vector with matrix;\n"
              << "3) matrix with vector;\n"
              << "4) scalar with matrix;\n"
              << "5) matrix with scalar.\n"
              << "Please enter the number of function. "
              << std::endl;
    std::cin >> chose;

    if (chose == 1) {
        double **A, **B, **C;
        int mat_1_row = 2,
                mat_1_col = 3,
                mat_2_row = 3,
                mat_2_col = 2;
        A = create_a_matrix(mat_1_row, mat_1_col);
        B = create_a_matrix(mat_2_row, mat_2_col);

        A[0][0] = 1;
        A[1][0] = 2;
        A[0][1] = 3;
        A[1][1] = 4;
        A[0][2] = 5;
        A[1][2] = 6;

        B[0][0] = 1;
        B[1][0] = 2;
        B[2][0] = 3;
        B[0][1] = 4;
        B[1][1] = 5;
        B[2][1] = 6;

        C = Multiply(mat_1_row, mat_1_col, A, mat_2_row, mat_2_col, B);

        std::cout << "The multiply of a matrix (2x3) {{1,3,5},{2,4,6}} "
                     "with a matrix (3x2) {{1,4},{2,5},{3,6}} is \n"
                  << std::endl;
        for (int i = 0; i < mat_1_row; i++) {
            for (int j = 0; j < mat_2_col; j++) {
                std::cout << C[i][j] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        release_the_matrix(mat_1_row, A);
        release_the_matrix(mat_2_row, B);
        release_the_matrix(mat_1_row, C);
    }
    else if (chose == 2) {
        double *E, **F, *G;
        int vec_col = 3,
            mat_2_row = 3,
            mat_2_col = 2;
        E = new double [vec_col];
        F = create_a_matrix(mat_2_row, mat_2_col);

        E[0] = 1;
        E[1] = 3;
        E[2] = 5;

        F[0][0] = 1;
        F[1][0] = 2;
        F[2][0] = 3;
        F[0][1] = 4;
        F[1][1] = 5;
        F[2][1] = 6;

        G = Multiply(vec_col, E, mat_2_row, mat_2_col, F);

        std::cout << "The multiply of a column vector (1x3) {1,3,5} "
                     "with a matrix (3x2) {{1,4},{2,5},{3,6}} is \n"
                  << std::endl;
        for (int j = 0; j < mat_2_col; j++) {
            std::cout << G[j] << "\t";
        }
        std::cout << "\n";

        delete[] E;
        delete[] G;
        release_the_matrix(mat_2_row, F);
    }
    else if (chose == 3) {
        double **H, *I, *J;
        int mat_row = 2,
            mat_col = 3,
            vec_row = 3;
        H = create_a_matrix(mat_row, mat_col);
        I = new double [vec_row];

        H[0][0] = 1;
        H[1][0] = 2;
        H[0][1] = 3;
        H[1][1] = 4;
        H[0][2] = 5;
        H[1][2] = 6;

        I[0] = 1;
        I[1] = 2;
        I[2] = 3;

        J = Multiply(mat_row, mat_col, H, vec_row, I);

        std::cout << "The multiply of a matrix (2x3) {{1,3,5},{2,4,6}} "
                     "with a row vector (3x1) {1,2,3} is \n"
                  << std::endl;
        for (int j = 0; j < mat_row; j++) {
            std::cout << J[j] << "\n";
        }

        release_the_matrix(mat_row, H);
        delete[] I;
        delete[] J;
    }
    else if (chose == 4) {
        double K, **L, **M;
        int mat_row = 3,
            mat_col = 2;
        K = 10;
        L = create_a_matrix(mat_row, mat_col);

        L[0][0] = 1;
        L[1][0] = 2;
        L[2][0] = 3;
        L[0][1] = 4;
        L[1][1] = 5;
        L[2][1] = 6;

        M = Multiply(K, mat_row, mat_col, L);

        std::cout << "The multiply of a scalar 10 "
                     "with a matrix (3x2) {{1,4},{2,5},{3,6}} is \n"
                  << std::endl;
        for (int i = 0; i < mat_row; i++) {
            for (int j = 0; j < mat_col; j++) {
                std::cout << M[i][j] << "\t";
            }
            std::cout << "\n";
        }

        release_the_matrix(mat_row, L);
        release_the_matrix(mat_row, M);
    }
    else if (chose == 5) {
        double **N, O, **P;
        int mat_row = 2,
            mat_col = 3;
        N = create_a_matrix(mat_row, mat_col);
        O = 10;

        N[0][0] = 1;
        N[1][0] = 2;
        N[0][1] = 3;
        N[1][1] = 4;
        N[0][2] = 5;
        N[1][2] = 6;

        P = Multiply(mat_row, mat_col, N, O);

        std::cout << "The multiply of a matrix (2x3) {{1,3,5},{2,4,6}} "
                     "with a scalar 10 is \n"
                  << std::endl;
        for (int i = 0; i < mat_row; i++) {
            for (int j = 0; j < mat_col; j++) {
                std::cout << P[i][j] << "\t";
            }
            std::cout << "\n";
        }

        release_the_matrix(mat_row, N);
        release_the_matrix(mat_row, P);
    }

    return 0;
}

double** create_a_matrix(int row, int column) {
    double **mat;
    mat = new double *[row];
    for (int i = 0; i < row; i++) {
        mat[i] = new double [column];
    }
    return mat;
}

void release_the_matrix(int row, double **mat) {
    if (row == 1) {
        delete[] mat;
    }
    else {
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
}

double **Multiply(int mat_1_r, int mat_1_c, double **mat_1,
                  int mat_2_r, int mat_2_c, double **mat_2) {
    double **result_mat;

    // assert that the matrices are of suitable sizes to be multiplied
    assert(mat_1_c == mat_2_r);

    result_mat = create_a_matrix(mat_1_r, mat_2_c);

    for (int i = 0; i < mat_1_r; i++)
    {
        for (int j = 0; j < mat_1_c; j++)
        {
            for (int k = 0; k < mat_1_c; k++)
            {
                result_mat[i][j] += (mat_1[i][k] * mat_2[k][j]);
            }
        }
    }

    return result_mat;
}

double *Multiply(int vec_c, double const *vec,
                  int mat_r, int mat_c, double **mat)
{
    double *result_mat;

    // assert that the matrices are of suitable sizes to be multiplied
    assert(vec_c == mat_r);

    result_mat = new double [mat_c];

    for (int j = 0; j < mat_c; j++)
    {
        for (int k = 0; k < vec_c; k++)
        {
            result_mat[j] += (vec[k] * mat[k][j]);
        }
    }

    return result_mat;
}

double *Multiply(int mat_r, int mat_c, double **mat,
                  int vec_r, double const *vec)
{
    double *result_mat;

    // assert that the matrices are of suitable sizes to be multiplied
    assert(mat_c == vec_r);

    result_mat = new double [mat_r];

    for (int j = 0; j < mat_r; j++)
    {
        for (int k = 0; k < vec_r; k++)
        {
            result_mat[j] += (mat[j][k] * vec[k]);
        }
    }

    return result_mat;
}

double **Multiply(double scalar,
                  int mat_r, int mat_c, double **mat)
{
    double **result_mat;

    result_mat = create_a_matrix(mat_r, mat_c);

    for (int j = 0; j < mat_r; j++)
    {
        for (int k = 0; k < mat_c; k++)
        {
            result_mat[j][k] = scalar * mat[j][k];
        }
    }

    return result_mat;
}

double **Multiply(int mat_r, int mat_c, double **mat,
                  double scalar)
{
    double **result_mat;

    result_mat = create_a_matrix(mat_r, mat_c);

    for (int j = 0; j < mat_r; j++)
    {
        for (int k = 0; k < mat_c; k++)
        {
            result_mat[j][k] = scalar * mat[j][k];
        }
    }

    return result_mat;
}
