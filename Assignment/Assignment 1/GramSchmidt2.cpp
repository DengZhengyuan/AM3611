/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: Assignment 1 Part B
    DESCRIPTION: 
            calculate the average value of an array
    CMD:    g++ GramSchmidt2.cpp -o GramSchmidt2 && ./GramSchmidt2
*/

#include <iostream>
#include <cmath>

/* ---------------------------------------------- */
/*                                                */
/* ---------------------------------------------- */

// the dot production
double dot_production(int size, double *vec_1, double *vec_2);

// the Euclidean norm
double Euclidean_norm(int size, double *array);

// the projection of vec_a onto vec_u
double *projection(int size, double *vec_u, double *vec_a);

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
/*                                                */
/* ---------------------------------------------- */

int main(int argc, char *argv[])
{
    /* ----------- start with matrix A ----------- */

    // input the size of matrix A
    int size;
    std::cout << "Please enter the dimension of matrix A. \n ";
    std::cout << "(If A is a (2x2) matrix, please enter 2). \n ";
    std::cin >> size; 

    // input the matrix A
    double **A;
    A = create_a_square_matrix(size); 
    std::cout << "Please enter the all elements of matrix A. \n";
    std::cout << "(Please enter the column vector in turn). \n ";
    for (int i = 0; i < size ; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> A[i][j];
        }
    }

    // here should assert if A is singular. 

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

    delete_matrix(size, A);

    double **QR; 
    QR = create_a_square_matrix(size); 
    QR = matrix_x_matrix(size, Q, R); 

    // print the matrix Q, R and QR
    {
        std::cout << "The matrix Q is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << Q[j][i] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        // print the matrix R
        std::cout << "The matrix R is " << std::endl;
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size; i++)
            {
                if (j < (i + 1))
                {
                    std::cout << R[i][j] << "  ";
                }
                else
                {
                    std::cout << 0 << "        ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        std::cout << "The matrix QR is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << QR[j][i] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    /* ----------- section b ----------- */

    double *b; 
    b = new double[size];
    std::cout << "Please enter the all elements of vector b. \n";
    for (int i = 0; i < size; i++)
    {
        std::cin >> b[i];
    }
    std::cout << "\n";

    // calculate the production of matrix QT and vector b
    double *QTb; 
    QTb = new double[size]; 
    QTb = matrixT_x_vector(size, Q, b); 

    delete_matrix(size, Q);

    // calculate the final results
    double *final_result; 
    final_result = new double[size]; 

    double R_x, numerator;
    for (int i = (size - 1); i >= 0; i--) { 
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

    std::cout << "The final results are \n"; 
    for (int i = 0; i < size; i++)
    {
        std::cout << final_result[i] 
                  << "\n";
    }
    std::cout << "\n";
    delete[] final_result;


    return 0;
}

/* ---------------------------------------------- */
/*                                                */
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
    double sum = 0.;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            sum += matrix[i][j] * vector[j];
        }
        result_vec[i] = sum; 
        sum = 0.;
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
    double sum = 0.;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                sum += m_1[k][j] * m_2[i][k]; 
            }
            result_m[i][j] = sum; 
            sum = 0.;
        }
    }

    return result_m;
}
