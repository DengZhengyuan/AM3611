/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 9, 2019
    PROB #: Assignment 1 Part B
    DESCRIPTION: 
            calculate the average value of an array
    CMD:    g++ GramSchmidt.cpp -o GramSchmidt && ./GramSchmidt
*/

#include <iostream>
#include <cmath>

// the dot production
double dot_production(int size, double *vec_1, double *vec_2);

// the Euclidean norm
double Euclidean_norm(int size, double *array);

// the projection of vec_a to vec_u
double* projection(int size, double *vec_u, double *vec_a);

// function to create a square matrix
double** create_a_square_matrix(int size);

// function to free the memory of a matrix
void delete_matrix(int size, double** matrix); 

/* ---------------------------------------------- */
/*                                                */
/* ---------------------------------------------- */

int main(int argc, char *argv[])
{   
    // define the size of matrix A
    int size = 2; 

    // define the matrixes of A, U, and e
    double **A, **U, **Q; 
    A = create_a_square_matrix(size);
    U = create_a_square_matrix(size);
    Q = create_a_square_matrix(size);

    // define the upper triangular matrix R
    double **R; 
    R = new double* [size];
    for (int i = 0; i < size; i++) {
        R[i] = new double [size - i]; 
    }

    // define the vector of projection
    double *Proj, *b;
    Proj = new double [size]; 
    b = new double [size]; 

    // initialize the matrix A and vector b
    A[0][0] = 3.; A[1][0] = 7.;
    A[0][1] = 1.; A[1][1] = 9.;
    b[0] = 0.;    b[1] = 5.;

    // calculate the matrix U
    U[0] = A[0];

    for (int i = 1; i < size; i++) { 
        U[i] = A[i]; 
        for (int j = 0; j < i; j++) {
            Proj = projection(size, U[j], A[i]);
            for (int k = 0; k < size; k++) {
                U[i][k] -= Proj[k];
            } 
            delete[] Proj; 
        }
    }
    
    // calculate the matrix Q
    for (int i = 0; i < size; i++) {         
        for (int j = 0; j < size; j++) {
            Q[i][j] = U[i][j] / Euclidean_norm(size, U[i]);
        }
    }

    // calculate the matrix R
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < (j+1); i++) {
            R[j][i] = dot_production(size, Q[i], A[j]); 
        }
    }
    

    for (int j = 0; j < size; j++) {
        for (int i = 0; i < (j+1); i++) {
            std::cout << R[j][i] << std::endl;
        }
    }

    /* ------------------------------------ */

    delete_matrix(size, A);
    delete_matrix(size, U); 
    delete_matrix(size, Q); 

    // free the memory of matrix R
    for (int i = 0; i < size; i++) {
        delete[] R[size - i]; 
    }
    delete[] R;

    delete[] b;

    return 0;
}

/* ---------------------------------------------- */
/*                                                */
/* ---------------------------------------------- */

double dot_production(int size, double *vec_1, double *vec_2)
{
    double result;
    for (int i = 0; i < size; i++) {
        result += vec_1[i] * vec_2[i];
    }
    return result;
}

double Euclidean_norm(int size, double *array)
{
    double result,
           sum;
    for (int i = 0; i < size; i++) {
        sum += pow(array[i], 2);
    }
    result = sqrt(sum);
    return result;
}

double* projection(int size, double *vec_u, double *vec_a)
{
    double *vec; 
    vec = new double [size];

    double coefficient;

    coefficient = dot_production(size, vec_u, vec_a) /
                  dot_production(size, vec_u, vec_u); 

    for (int i = 0; i < size; i++) {
        vec[i] = vec_u[i] * coefficient;
    }

    return vec;
}

double** create_a_square_matrix(int size)
{
    double** matrix; 
    matrix = new double* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new double [size];
    }
    return matrix; 
}

void delete_matrix(int size, double** matrix)
{
    for (int i = 1; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}