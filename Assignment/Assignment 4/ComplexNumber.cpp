/*
    NAME:   Zhengyuan Deng
    STU #:  251006745
    DATA:   Oct. 30, 2019
    PROB #: problem 6.1
    DESCRIPTION:
            extend the ComplexNumber class
            the source code file
*/

#include "ComplexNumber.h"
#include <cmath>

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

// Method for computing the modulus of a
// complex number
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart + mImaginaryPart*mImaginaryPart);
}

// Method for computing the argument of a
// complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n
// using De Moivre's theorem - first complex
// number must be converted to polar form
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument*n;
    double real_part = mod_of_result*cos(arg_of_result);
    double imag_part = mod_of_result*sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

// Overloading the = (assignment) operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    return *this;
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mRealPart = -mRealPart;
    w.mImaginaryPart = -mImaginaryPart;
    return w;
}

// Overloading the binary + operator
ComplexNumber operator+(const ComplexNumber& z1, const ComplexNumber& z2)
{
    ComplexNumber w;
    w.mRealPart = z1.mRealPart + z2.mRealPart;
    w.mImaginaryPart = z1.mImaginaryPart + z2.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber operator-(const ComplexNumber& z1, const ComplexNumber& z2)
{
    ComplexNumber w;
    w.mRealPart = z1.mRealPart - z2.mRealPart;
    w.mImaginaryPart = z1.mImaginaryPart - z2.mImaginaryPart;
    return w;
}

// Overloading the insertion << operator
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z)
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
    return output;
}

/*---------- Extension of ComplexNumber class ----------*/

// Method for get real part of a complex number
double ComplexNumber::GetRealPart() const {
    return mRealPart;
}

// Method for get real part of a complex number
double ComplexNumber::GetImaginaryPart() const {
    return mImaginaryPart;
}

// friend method for get real part
double RealPart(const ComplexNumber& z) {
    return z.mRealPart;
}

// friend method for get imaginary part
double ImaginaryPart(const ComplexNumber& z) {
    return z.mImaginaryPart;
}

// overridden copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber& other_complex_number) {
    mRealPart = other_complex_number.mRealPart;
    mImaginaryPart = other_complex_number.mImaginaryPart;
}

// specify a real number in complex form


// const method to calculate the conjugate
ComplexNumber ComplexNumber::CalculateConjugate() const {
    return ComplexNumber(mRealPart, -mImaginaryPart);
}

// method to calculate the conjugate with void return type
void ComplexNumber::SetToConjugate() {
    mImaginaryPart = -mImaginaryPart;
}
