#include <iostream>
#include <string>
#include <vector>

#include "Complex.hpp"

template<class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &v) {
    for (auto &i : v) {
        os << i << std::endl;
    }
    return os;
}

int main(int argc, char const *argv[]) {
    std::vector<Complex> v({
        Complex(-1.2,  6.3),
        Complex( 4.0,  0.7),
        Complex( 7.2, -0.8),
        Complex( 5.3,  3.0),
        Complex(-4.9,  6.6),
        Complex(-9.3,  0.2)
    });
    std::cout << v << std::endl;
    Complex ans(0, 0);
    for (auto &i : v) {
        ans += i;
    }
    std::cout << "Sum is " << ans << std::endl;
    return 0;
}
