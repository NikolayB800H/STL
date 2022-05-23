#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

class Generator {
public:
    Generator() {
        std::srand(std::time(nullptr));
    }
    float operator()() {
        return (static_cast<float>(std::rand())) / std::rand();
    }
};

template<class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &v) {
    for (auto &i : v) {
        os << i << ' ';
    }
    return os;
}

int main(int argc, char const *argv[]) {
    std::vector<float> v(25, 0);
    std::generate(v.begin(), v.end(), Generator());
    std::cout << "Before: " << v << std::endl;
    for (auto &i : v) {
        i *= i;
    }
    std::cout << "After: " << v << std::endl;
    v.erase(v.begin() + 5);
    std::cout << "Again: " << v << std::endl;
    return 0;
}
