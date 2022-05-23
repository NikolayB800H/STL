#include <iostream>
#include <string>
#include <vector>

#include "Card.hpp"

template<class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &v) {
    for (auto &i : v) {
        os << i << std::endl;
    }
    return os;
}

int main(int argc, char const *argv[]) {
    std::vector<Card> v({
        Card("Secret views of mount Fuji", "Pelevin", 7),
        Card("Ghost in the shell", "Masanori", 0),
        Card("Robot dreams", "Asimov", 1),
        Card("Robot visions", "Asimov", 2),
        Card("The time machine", "Wells", 3)
    });
    std::cout << v << std::endl;
    std::string author;
    std::cout << "Author: ";
    std::cin >> author;
    bool is_there = false;
    for (auto &i : v) {
        if (i.isByAuthor(author)) {
            is_there = true;
            std::cout << i << std::endl;
        }
    }
    if (!is_there) {
        std::cout << "Unknown author." << std::endl;
    }
    return 0;
}
