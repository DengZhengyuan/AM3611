/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 27, 2019
    PROB #: problem 2.2a
    DESCRIPTION: 
            test the if statement
    CMD:    g++ problem2_2a.cpp -o problem2_2a.out && ./problem2_2a.out
*/


#include <iostream>

int main(int argc, char const *argv[]) 
{
  double p, q, x, y;
  int j;

  std::cout << "Please enter the 'p', 'q', and 'j'. \n";
  std::cin >> p >> q >> j; 
  
  if(p >= q || j != 10)
  {
    x = 5; 
  }

  std::cout << "x = " << x << std::endl;

  return 0;
}
