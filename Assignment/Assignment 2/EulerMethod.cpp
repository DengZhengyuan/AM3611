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
#include <cstdlib>

/*---------------------------------------*/
/*               functions               */
/*---------------------------------------*/

// the production of a matrix and a vector
double *matrix_x_vector(int size, double **matrix, double *vector);
// create a square matrix
double **create_a_square_matrix(int size);
// release the memory of matrix
void delete_matrix(int size, double **matrix);


/*---------------------------------------*/
/*             main function             */
/*---------------------------------------*/
int main(int argc, char *argv[])
{
    /*--------- Command line argument part ---------*/
    int size = 3,
        Number_of_command_line_arguments = 0;

    // test the number of command line argument
    for (int i = 0; i < argc; i++)
    {
        Number_of_command_line_arguments = (i + 1);
    }
    if (Number_of_command_line_arguments != 3)
    {
        std::cerr << "The number of command line arguments is incorrect.\n";
        std::cerr << "Please input the data file name (.dat) and the number of nodes after './EulerMethod.out'. \n";
        return 1;
    }
    
    // define the variables in Euler method
    double **A, 
           *Ay;
    A = create_a_square_matrix(size);
    Ay = new double[size];

    double y[size],
           x = 0,
           h;

    // read the data file and the number of nodes
    std::string data_file_name = argv[1]; 
    double N = atof(argv[2]); 

    assert((N > 1)); 
    h = 1 / (N-1.);
    
    /*------------ Read the file part ------------*/
    // read the A and y0
    std::ifstream read_file(data_file_name);
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
    
    // write the initial value to the results file
    std::ofstream write_file("xy_test.dat");
    write_file.precision(10);
    write_file << x << " ";
    for (int i = 0; i < size; i++)
    {
        write_file << y[i] << " ";
    }
    write_file << "\n";
    write_file.flush();
    
    /*--------- Calculation and write the results part ---------*/
    // calculate the results and write them to the file
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
    
    // close the file
    write_file.close();
    
    // release the memory
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
