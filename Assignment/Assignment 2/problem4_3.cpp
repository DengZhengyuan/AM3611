/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 28, 2019
    PROB #: problem 4.1
    DESCRIPTION: 
            handle the pointers for matrix
    CMD:    g++ problem4_3.cpp -o problem4_3.out && ./problem4_3.out
*/
#include <iostream>

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


int main(int argc, char const *argv[])
{
  int size = 2;
  double **A, 
         **B, 
         **C; 
  A = create_a_square_matrix(size); 
  B = create_a_square_matrix(size); 
  C = create_a_square_matrix(size); 

  A[0][0] = 1;
  A[0][1] = 2; 
  A[1][0] = 3;
  A[1][1] = 4;

  B[0][0] = 5;
  B[0][1] = 6; 
  B[1][0] = 7;
  B[1][1] = 8;

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      C[i][j] = A[i][j] + B[i][j]; 
    }
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      std::cout << C[i][j] << "\t";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

  delete_matrix(size, A);
  delete_matrix(size, B);
  delete_matrix(size, C); 

  return 0;
}