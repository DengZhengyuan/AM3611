/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 27, 2019
    PROB #: problem 2.3
    DESCRIPTION: 
            calculate a list of numbers
    CMD:    g++ problem2_3.cpp -o problem2_3.out && ./problem2_3.out
*/

#include <iostream>

int main(int argc, char *argv[])
{
  int data = 0, 
      sum = 0; 

  std::cout << "\n"
            << "Please enter the positive integers and end with '-1'. \n" 
            << "(For example, '1 2 3 4 5 -1'.) \n"
            << std::endl;
  
  do {
    std::cin >> data;
    if (data >= 0)
    {
      sum += data;
    }
    else if (data != -1)
    {
      std::cout << "\nYou entered the wrong number, the sum has been reset. \n";
      sum = 0;
      data = 0; 
    }
  } while(data != -1 && sum <= 100); 

  std::cout << "\n"
            << "The sum of integers you entered is "
            << sum 
            << ".\n\n";

  return 0;
}