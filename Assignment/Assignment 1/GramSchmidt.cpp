/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 10, 2019
    PROB #: Assignment 1 Part B
    DESCRIPTION: 
            solve a system of linear equations by 
            Gram-Schmidt process
    CMD:    g++ GramSchmidt.cpp -o GramSchmidt.out && ./GramSchmidt.out
*/

#include <iostream>
#include <cmath>
#include <cassert> // assert

/* ---------------------------------------------- */
/*                   FUNCTIONS                    */
/* ---------------------------------------------- */

// the dot production
double dot_production(int size, double *vec_1, double *vec_2);

// the Euclidean norm
double Euclidean_norm(int size, double *array);

// the projection of vec_a onto vec_u
double *projection(int size, double *vec_u, double *vec_a);

// calculate the determinate of a matrix
// now only two dimensions matrix can be calculated
double determinate(int size, double **matrix);

// transpose a square matrix and calculate the
// production of it and a vector
double *matrixT_x_vector(int size, double **matrix, double *vector);

// production of two matrixes
double **matrix_x_matrix(int size, double **m_1, double **m_2);

// function to create a square matrix
double **create_a_square_matrix(int size);

// function to create an upper triangle matrix
double **create_an_upper_triangle_matrix(int size);

// function to free the memory of a matrix
void delete_matrix(int size, double **matrix);

/* ---------------------------------------------- */
/*                 MAIN FUNCTION                  */
/* ---------------------------------------------- */

int main(int argc, char *argv[])
{
    /* ----------- start with matrix A ----------- */

    // input the size of matrix A
    int size;
    std::cout << "Please enter the dimension of matrix A. \n";
    std::cout << "(If A is a (2x2) matrix, please enter 2). \n";
    std::cin >> size;
    std::cout << "\n";

    // input the matrix A
    double **A;
    A = create_a_square_matrix(size);
    std::cout << "Please enter the all elements of matrix A. \n";
    std::cout << "(Please enter the column vector in turn). \n";
    std::cout << "(For this problem, please enter 3 1 7 9). \n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> A[i][j];
        }
    }
    std::cout << "\n";

    // assert if A is singular.
    assert(determinate(size, A) != 0); 


    /* ----------- Matrix U, Q, and R ----------- */

    // define the matrixes of U, Q and R
    double **U, **Q, **R;
    U = create_a_square_matrix(size);
    Q = create_a_square_matrix(size);
    R = create_an_upper_triangle_matrix(size);

    // calculate the matrix U
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            U[i][j] = A[i][j];
        }

        for (int j = 0; j < i; j++)
        {
            double *Proj;
            Proj = new double[size];
            Proj = projection(size, U[j], A[i]);
            for (int k = 0; k < size; k++)
            {
                U[i][k] -= Proj[k];
            }
            delete[] Proj;
        }
    }

    // calculate the matrix Q
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Q[i][j] = U[i][j] / Euclidean_norm(size, U[i]);
        }
    }

    delete_matrix(size, U);

    // calculate the matrix R
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < (j + 1); i++)
        {
            R[j][i] = dot_production(size, Q[i], A[j]);
        }
    }

    // calculate the Q times R, and check it with A
    double **QR, **R_square;
    QR = create_a_square_matrix(size);
    R_square = create_a_square_matrix(size);

    // change the data structure of R from upper triangle 
    // matrix to square matrix
    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < size; i++)
        {
            if (j < (i + 1))
            {
                R_square[i][j] = R[i][j];
            }
            else
            {
                R_square[i][j] = 0 ;
            }
        }
    }

    QR = matrix_x_matrix(size, Q, R_square);

    double **QR_err; 
    QR_err = create_a_square_matrix(size); 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            QR_err[i][j] = (QR[i][j] - A[i][j]) / A[i][j];
        }
    }

    // print out the matrix Q, R and QR
    {
        std::cout << "The matrix Q is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << Q[j][i] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        // print out the matrix R
        std::cout << "The matrix R is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << R_square[j][i] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "The matrix QR is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << QR[j][i] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "Comparing with A, the relative error of QR is " 
                  << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << QR_err[j][i] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            assert(QR_err[i][j] < pow(10, -6));
        }
    }

    delete_matrix(size, A);
    delete_matrix(size, QR);
    delete_matrix(size, QR_err);
    delete_matrix(size, R_square);

    /* ------------ Vector b ------------ */

    double *b;
    b = new double[size];
    std::cout << "Please enter the all elements of vector b. \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> b[i];
    }
    std::cout << "\n";

    /* ------ calculate the results ------ */

    // calculate the production of matrix QT and vector b
    double *QTb;
    QTb = new double[size];
    QTb = matrixT_x_vector(size, Q, b);

    delete_matrix(size, Q);

    // calculate the final results
    double *final_result;
    final_result = new double[size];

    double R_x = 0., 
           numerator = 0.;
    for (int i = (size - 1); i >= 0; i--)
    {
        if (i == (size - 1))
        {
            R_x = 0.;
        }
        else
        {
            for (int j = (size - 1); j > i; j--)
            {
                R_x += (R[j][i] * final_result[j]);
            }
        }
        numerator = QTb[i] - R_x;
        R_x = 0.;
        final_result[i] = numerator / R[i][i];
        numerator = 0.;
    }
    delete[] b;
    delete[] QTb;
    delete_matrix(size, R);

    // print out the final results
    std::cout << "The final results are \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << final_result[i]
                  << "\n";
    }
    std::cout << "\n";

    // check the relative errores 
    std::cout << "The norm of relative error for this problem is \n"; 
    double real_x_0 = -1.75, 
           real_x_1 = 0.75, 
           norm_of_err = 0.; 
           norm_of_err = sqrt(
                    pow((final_result[0] - real_x_0) / real_x_0, 2) +
                    pow((final_result[1] - real_x_1) / real_x_1, 2));
    std::cout << norm_of_err
              << "\n";

    delete[] final_result;

    return 0;
}

/* ---------------------------------------------- */
/*                DEFINE FUNCTIONS                */
/* ---------------------------------------------- */

double dot_production(int size, double *vec_1, double *vec_2)
{
    double result = 0.;
    for (int i = 0; i < size; i++)
    {
        result += vec_1[i] * vec_2[i];
    }
    return result;
}

double Euclidean_norm(int size, double *array)
{
    double result = 0.,
           sum = 0.;
    for (int i = 0; i < size; i++)
    {
        sum += pow(array[i], 2);
    }
    result = sqrt(sum);
    return result;
}

double *projection(int size, double *vec_u, double *vec_a)
{
    double *vec;
    vec = new double[size];

    double coefficient = 0.;

    coefficient = dot_production(size, vec_u, vec_a) /
                  dot_production(size, vec_u, vec_u);

    for (int i = 0; i < size; i++)
    {
        vec[i] = vec_u[i] * coefficient;
    }

    return vec;
}

double *matrixT_x_vector(int size, double **matrix, double *vector)
{
    double *result_vec;
    result_vec = new double[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result_vec[i] += matrix[i][j] * vector[j];
        }
    }
    return result_vec;
}

double **create_a_square_matrix(int size)
{
    double **matrix;
    matrix = new double *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size];
    }
    return matrix;
}

double **create_an_upper_triangle_matrix(int size)
{
    double **matrix;
    matrix = new double *[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = new double[size - 1];
    }
    return matrix;
}

void delete_matrix(int size, double **matrix)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double **matrix_x_matrix(int size, double **m_1, double **m_2)
{
    double **result_m;
    result_m = create_a_square_matrix(size); 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                result_m[i][j] += m_1[k][j] * m_2[i][k];
            }
        }
    }

    return result_m;
}

double determinate(int size, double **matrix)
{
    double det = 0.;
    if (size == 2)
    {
        det =
            matrix[0][0] * matrix[1][1] -
            matrix[1][0] * matrix[0][1];
    }
    else if (size == 3)
    {
        det =
            matrix[0][0] * matrix[1][1] * matrix[2][2] +
            matrix[1][0] * matrix[2][1] * matrix[0][2] +
            matrix[2][0] * matrix[0][1] * matrix[1][2] -
            matrix[2][0] * matrix[1][1] * matrix[0][2] -
            matrix[1][0] * matrix[0][1] * matrix[2][2] -
            matrix[0][0] * matrix[2][1] * matrix[1][2];
    }
    else
    {
        det = 1;
        std::cout << "Determinant returns 1 when the dimension is larger than 3.";
    }

    return det;
}