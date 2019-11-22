/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Nov. 20, 2019
    PROB #: problem 8.3
    DESCRIPTION:
            template to different type list
    CMD:
            g++ -std=c++11 problem8_3.cpp -o problem8_3.out && ./problem8_3.out
*/

#include <iostream>
#include <cmath>
#include "ComplexNumber.h"
// #include "List.h"

template <typename type>
type abs_value(type value)
{
    if (value >= static_cast<type>(0))
        return value;
    return -value;
}

template <typename type>
class List
{
private:
    type *m_vector;
    int m_length;

public:
    // constractor
    explicit List(int length) : m_length(length), m_vector(new type[length]) {}

    // destractor
    ~List() {
        delete[] m_vector;
    }

    // get the length of the list
    int getLength() const {
        return m_length;
    }

    // overload the '[]'
    type &operator[](int i) {
        return m_vector[i];
    }
    const type &operator[](int i) const {
        return m_vector[i];
    }

    // calculate the sum of the elements in the list
    type sum() const {
        type result;
        for (int i = 0; i < m_length; i++)
            result += m_vector[i];
        return result;
    }

    // calculate the p norm
    double pNorm(double p = 2.0) const {
        double sum = 0.;
        for (int i = 0; i < m_length; i++)
        {
            sum += std::pow(abs_value(m_vector[i]), p);
        }
        return std::pow(sum, 1./p);
    }
};

// Print a list.
template <typename type>
std::ostream &operator<<(std::ostream &os, const List<type> &list)
{
    os << "{";
    for (int i = 0; i < list.getLength(); i++)
    {
        if (i > 0)
            os << ", ";
        os << list[i];
    }
    os << "}";

    return os;
}

/* ---------------------------------------------------- */
/*                     Main Function                    */
/* ---------------------------------------------------- */
int
main(int argc, char *argv[])
{
    List<int> test1(3);
    test1[0] = 3;
    test1[1] = 5;
    test1[2] = 7;
    std::cout << "List double : " << test1 << std::endl;
    std::cout << "sum: " << test1.sum() << std::endl;
    std::cout << "2-norm: " << test1.pNorm() << std::endl;
    std::cout << "5-norm: " << test1.pNorm(5.) << std::endl;

    List<double> test2(3);
    test2[0] = 2.4;
    test2[1] = 1.1;
    test2[2] = 5.7;
    std::cout << "List double : " << test2 << std::endl;
    std::cout << "sum: " << test2.sum() << std::endl;
    std::cout << "2-norm: " << test2.pNorm() << std::endl;
    std::cout << "5-norm: " << test2.pNorm(5.) << std::endl;

    List<ComplexNumber> test3(3);
    test3[0] = ComplexNumber(1,1);
    test3[1] = ComplexNumber(2,2);
    test3[2] = ComplexNumber(3,3);

    std::cout << "List double : " << test3 << std::endl;
    std::cout << "sum: " << test3.sum() << std::endl;
    std::cout << "2-norm: " << test3.pNorm() << std::endl;
    std::cout << "5-norm: " << test3.pNorm(5.) << std::endl;

    return 0;
}
