/* 
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Sept. 28, 2019
    PROB #: problem 4.1
    DESCRIPTION: 
            handle the pointers for int
    CMD:    g++ problem4_1.cpp -o problem4_1.out && ./problem4_1.out
*/

#include <iostream>

int main(int argc, char const *argv[])
{
  // define the variable and pointers
  int i = 5, 
      *p_j = &i, 
      *p_k;

  // multiply i by 5 by the pinter p_j
  i = *p_j * 5;

  p_k = new int; 

  *p_k = i; 
  *p_j = 0; 

  std::cout << "The value of i = " << i << std::endl;
  std::cout << "The value pointed to by p_j = " << *p_j << std::endl;
  std::cout << "The value pointed to by p_k = " << *p_k << std::endl;

  delete p_k;
  
  return 0;
}
