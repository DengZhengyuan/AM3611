/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 28, 2019
    PROB #: problem 3.2
    DESCRIPTION: 
            read a file
    CMD:    g++ problem3_2.cpp -o problem3_2.out && ./problem3_2.out
*/

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[]) {
  std::ifstream read_file("x_and_y.dat");
  if(!read_file.is_open())
  {
    return 1;
  }
  int number_of_rows = 0;
  while(!read_file.eof())
  {
    double dummy1, dummy2, dummy3, dummy4;
    read_file >> dummy1 >> dummy2;
    read_file >> dummy3 >> dummy4;
    if (!read_file.fail())
    {
      number_of_rows++;
    }  
  }
  
  std::cout << "Number of row = " << number_of_rows << "\n";

  read_file.close();
  return 0;
}
