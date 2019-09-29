/*
 NAME:   Zhengyuan Deng
 STU #:  251006745
 DATA:   Sept. 29, 2019
 PROB #: assignment 2 part B
 DESCRIPTION:
         Solve the ODE systems by Euler method
 CMD:    g++ EulerMethod.cpp -o EulerMethod.out && ./EulerMethod.out
 */

#include <iostream>
#include <fstream>
#include <cassert>

/*---------------------------------------*/
/*               functions               */
/*---------------------------------------*/

// the production of a matrix and a vector
double *matrix_x_vector(int size, double **matrix, double *vector);

double **create_a_square_matrix(int size);

void delete_matrix(int size, double **matrix);


/*---------------------------------------*/
/*             main function             */
/*---------------------------------------*/
int main(int argc, char const *argv[])
{
    int size = 3;
    
    double **A, *Ay;
    A = create_a_square_matrix(size);
    Ay = new double[size];
    
    double y[size],
           x = 0,
           h,
           N;
    
    // read the A and y0
    std::ifstream read_file("data.dat");
    assert(read_file.is_open());
    for (int i = 0; i < (size+1); i++)
    {
        if (i < size)
        {
            read_file >> A[i][0] >> A[i][1] >> A[i][2];
        }
        else
            read_file >> y[0] >> y[1] >> y[2];
    }
    
    std::ofstream write_file("xy.dat");
    write_file.precision(10);
    write_file << x << " ";
    for (int i = 0; i < size; i++)
    {
        write_file << y[i] << " ";
    }
    write_file << "\n";
    write_file.flush();
    
    
    std::cout << "Please enter the N value. " << std::endl;
    std::cin >> N;
    h = 1 / (N-1);
    
    for (int j = 0; j < (N-1); j++)
    {
        Ay = matrix_x_vector(size, A, y);
        for (int i = 0; i < size; i++)
        {
            y[i] = y[i] + h * Ay[i];
        }
        x = (j+1) * h;
        
        write_file.setf(std::ios::app);
        write_file.precision(10);
        write_file << x << " ";
        for (int i = 0; i < size; i++)
        {
            write_file << y[i] << " ";
        }
        write_file << "\n";
        write_file.flush();
    }
    
    
    write_file.close();
    
    delete_matrix(size, A);
    delete[] Ay;
    
    return 0;
}



/*---------------------------------------*/
/*            define functions           */
/*---------------------------------------*/
double *matrix_x_vector(int size, double **matrix, double *vector)
{
    double *result;
    result = new double[size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    return result;
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

void delete_matrix(int size, double **matrix)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
