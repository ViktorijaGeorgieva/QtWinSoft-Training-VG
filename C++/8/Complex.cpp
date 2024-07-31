#include <iostream>

using namespace std;

#include "Complex.h"

Complex::Complex(double r, double i) : real(r), imaginary(i) { }

Complex Complex::operator+(const Complex &operand2) const {
    return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const {
    return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex &operand2) const {
    double realResult = (real * operand2.real) - (imaginary * operand2.imaginary);
    double imaginaryResult = (real * operand2.imaginary) + (imaginary * operand2.real);
    return Complex(realResult, imaginaryResult);
}

Complex Complex::operator*(int number) const {
    return Complex(real * number, imaginary * number);
}

Complex operator*(int number, const Complex &operand2) {
    return Complex(number * operand2.real, number * operand2.imaginary);
}

bool Complex::operator==(const Complex &operand2) const {
    return (real == operand2.real && imaginary == operand2.imaginary);
}

bool Complex::operator!=(const Complex &operand2) const {
    return !(*this == operand2);
}

Complex& Complex::operator+=(const Complex &operand2) {
    *this = *this + operand2;
    return *this;
}

Complex& Complex::operator-=(const Complex &operand2) {
    *this = *this - operand2;
    return *this;
}

Complex& Complex::operator*=(const Complex &operand2) {
    *this = *this * operand2;
    return *this;
}

ostream &operator<<(ostream &output, const Complex &number) {
    output << '(' << number.real << ", " << number.imaginary << ')';
    return output;
}

istream &operator>>(istream &input, Complex &number) {
    input >> number.real >> number.imaginary;
    return input;
}
