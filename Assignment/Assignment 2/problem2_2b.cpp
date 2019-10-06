/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 27, 2019
    PROB #: problem 2.2b
    DESCRIPTION: 
            test the if statement
    CMD:    g++ problem2_2b.cpp -o problem2_2b.out && ./problem2_2b.out
*/


#include <iostream>

int main(int argc, char const *argv[]) {
  double p, q, x, y;
  int j;

  std::cout << "Please enter the 'p', 'q', ‘y’, and 'j'. \n";
  std::cin >> p >> q >> y >> j; 

  if(y >= q && j == 20)
  {
    x = 5;
  }
  else
  {
    x = p;
  }
  
  std::cout << "x = " << x << std::endl;

  return 0;
}
