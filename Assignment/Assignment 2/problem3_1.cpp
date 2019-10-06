/* 
 NAME:   Zhengyuan Deng
 STU #:  251006745
 DATA:   Sept. 27, 2019
 PROB #: problem 3.1
 DESCRIPTION:
 calculate a list of numbers
 CMD:    g++ problem3_1.cpp -o problem3_1.out && ./problem3_1.out
 */

#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
  double x[4] = {0.0, 1.0, 1.0, 0.0};
  double y[4] = {0.0, 0.0, 1.0, 1.0};
  char char_judge;
  bool bool_judge;

  std::ifstream read_file("x_and_y.dat");
  bool_judge = read_file.is_open();
  read_file.close();

  if (bool_judge == 1)
  {
    std::cout << "\nWarning: 'x_and_y.data' exists, overwrite the file? [y/n]"
              << std::endl;
    std::cin >> char_judge;
    if (char_judge == 'y' || char_judge == 'Y')
    {
      std::ofstream write_file("x_and_y.dat");
      {
        write_file.setf(std::ios::scientific);
        write_file.setf(std::ios::showpos);
        write_file.precision(10);

        for (int i = 0; i < 4; i++)
        {
          write_file << x[i] << " ";
        }
        write_file << "\n";

        write_file.flush();

        for (int i = 0; i < 4; i++)
        {
          write_file << y[i] << " ";
        }
        write_file << "\n";
      }
      // close the file
      write_file.close();
    }
    else if (char_judge == 'n' || char_judge == 'N')
    {
      std::ofstream write_file("x_and_y.dat", std::ios::app);
      {
        write_file.setf(std::ios::scientific);
        write_file.setf(std::ios::showpos);
        write_file.precision(10);

        for (int i = 0; i < 4; i++)
        {
          write_file << x[i] << " ";
        }
        write_file << "\n";

        write_file.flush();

        for (int i = 0; i < 4; i++)
        {
          write_file << y[i] << " ";
        }
        write_file << "\n";
      }
      // close the file
      write_file.close();
    }
  }
  else if (bool_judge == 0)
  {
    std::ofstream write_file("x_and_y.dat");
    {
      write_file.setf(std::ios::scientific);
      write_file.setf(std::ios::showpos);
      write_file.precision(10);

      for (int i = 0; i < 4; i++)
      {
        write_file << x[i] << " ";
      }
      write_file << "\n";

      write_file.flush();

      for (int i = 0; i < 4; i++)
      {
        write_file << y[i] << " ";
      }
      write_file << "\n";
    }
    // close the file
    write_file.close();
  }

  return 0;
}
