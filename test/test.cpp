/*
g++ test.cpp -o test && ./test
*/
#include <iostream>

double **create_a_square_matrix(int size); 
void delete_matrix(int size, double **matrix);
double **matrix_x_matrix(int size, double **m_1, double **m_2);


int main(int argc, char *argv[])
{
    int size = 2;
    double **a, **b, **c; 
    a = create_a_square_matrix(size); 
    b = create_a_square_matrix(size); 
    c = create_a_square_matrix(size); 
    a[0][0] = 1;
    a[1][0] = 2;
    a[0][1] = 3;
    a[1][1] = 4;
    b[0][0] = 1;
    b[1][0] = 2;
    b[0][1] = 3;
    b[1][1] = 4;

    c = matrix_x_matrix(size, a, b);

    std::cout << "The matrix c is " << std::endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << c[j][i] << "  ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

    return 0;
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

void delete_matrix(int size, double **matrix)
{
    for (int i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}