#include <iostream>
#include <map>

template<class Key, class T>
std::ostream &operator<<(std::ostream &os, std::map<Key, T> const &m) {
    for (auto &i : m) {
        os << i.first << " - " << i.second << std::endl;
    }
    return os;
}

int main(int argc, char const *argv[]) {
    std::map<int, int> m;
    for (int i = 1; i <= 20; ++i) {
        m[i] = i * 10;
    }
    std::cout << "Before:\n" << m << std::endl;
    bool finished = false;
    while (!finished) {
        finished = true;
        for (auto &i : m) {
            if (i.first % 2) {
                m.erase(i.first);
                finished = false;
                break;
            }
        }
    }
    std::cout << "After:\n" << m << std::endl;
    return 0;
}
