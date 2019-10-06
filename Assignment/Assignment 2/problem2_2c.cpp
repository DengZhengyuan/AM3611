/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 27, 2019
    PROB #: problem 2.2c
    DESCRIPTION: 
            test the if statement
    CMD:    g++ problem2_2c.cpp -o problem2_2c.out && ./problem2_2c.out
*/


#include <iostream>

int main(int argc, char const *argv[]) {
  double p, q, x, y;
  int j;

  std::cout << "Please enter the 'p', 'q', and 'j'. \n";
  std::cin >> p >> q >> j; 

  if(p < q)
  {
    x = 0;
  }
  else if(p <= q || j ==10)
  {
    x = 1;
  }
  else
  {
    x = 2;
  }
  
  std::cout << "x = " << x << std::endl;

  return 0;
}
