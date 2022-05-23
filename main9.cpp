#include <iostream>
#include <map>
#include <string>

template<class Key, class T>
std::ostream &operator<<(std::ostream &os, std::map<Key, T> const &m) {
    for (auto &i : m) {
        os << i.first << " - " << i.second << std::endl;
    }
    return os;
}

int main(int argc, char const *argv[]) {
    std::map<std::string, size_t> first {
        {"Ivanov", 45500},
        {"Petrov", 37000},
        {"Sidorov", 245000},
        {"Petrenko", 65000},
        {"Tovalds", 91200},
        {"Popov", 54600},
        {"Andrienko", 35000}
    };
    std::map<std::string, std::string> second {
        {"Ivanov", "Research"},
        {"Petrov", "Research"},
        {"Sidorov", "Management"},
        {"Petrenko", "Management"},
        {"Tovalds", "Development"},
        {"Popov", "Research"},
        {"Andrienko", "Sales"}
    };
    std::map<std::string, size_t> third;
    size_t sum = 0;
    for (auto &i : first) {
        sum += i.second;
        if (third.find(second[i.first]) == third.end()) {
            third[second[i.first]] = i.second;
        } else {
            third[second[i.first]] += i.second;
        }
    }
    std::cout << third << "Overall - " << sum << std::endl;
    return 0;
}
