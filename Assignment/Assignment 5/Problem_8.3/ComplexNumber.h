/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.1
    DESCRIPTION:
            extend the ComplexNumber class
            the header file
*/

#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

#include <iostream>

class ComplexNumber
{
private:
    double mRealPart{};
    double mImaginaryPart{};
public:
    explicit ComplexNumber(double x = 0, double y = 0);
    double CalculateModulus() const;
    double CalculateArgument() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber& operator=(const ComplexNumber& z);
    ComplexNumber& operator+=(const ComplexNumber& z);
    ComplexNumber operator-() const;
    friend ComplexNumber operator+(const ComplexNumber& z1, const ComplexNumber& z2);
    friend ComplexNumber operator-(const ComplexNumber& z1, const ComplexNumber& z2);
    friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& z);
};

double abs_value(const ComplexNumber &x);

#endif // COMPLEXNUMBERHEADERDEF

