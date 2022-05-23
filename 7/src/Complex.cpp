#include <fstream>
#include <string>

#include "Complex.hpp"

Complex::Complex() : a(0), b(0) {
}

Complex::Complex(double a, double b) : a(a), b(b) {
}

Complex &Complex::operator+=(Complex const &other) {
    a += other.a;
    b += other.b;
    return *this;
}

std::ostream &operator<<(std::ostream &os, Complex const &complex) {
    os << complex.a;
    if (complex.b < 0) {
        os << "-i*" << -complex.b;
        return os;
    }
    os << "+i*" << complex.b;
    return os;
}
