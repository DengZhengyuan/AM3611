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

  std::ifstream read_file("x_and_y.dat");
  read_file.is_open();

  if (read_file.is_open())
  {
    std::cout << "Overwrite the file? [y/n] \n"
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
  else
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
  read_file.close();

  return 0;
}
