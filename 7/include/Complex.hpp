#pragma once

#include <fstream>
#include <string>

class Complex {
public:
    Complex();
    Complex(double a, double b);
    Complex &operator+=(Complex const &other);
    friend std::ostream &operator<<(std::ostream &os, Complex const &complex);
private:
    double a;
    double b;
};
