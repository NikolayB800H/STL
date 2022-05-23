#include <iostream>
#include <list>

template<class T>
bool contains(std::list<T> const &l, T const &elem) {
    for (typename std::list<T>::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
        if (*it == elem) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    std::list<int> l({-1, 2, -3, 4, -5});
    int test = 0;
    std::cout << "Number: "; 
    std::cin >> test;
    std::cout << "Is in list = " << (contains(l, test) ? "Yes" : "No")
              << std::endl;
    return 0;
}
