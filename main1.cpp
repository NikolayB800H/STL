#include <iostream>
#include <string>

constexpr char TO_FIND = ';';

int main(int argc, char const *argv[]) {
    std::string text;
    getline(std::cin, text, '\n');
    size_t pos = text.find(TO_FIND);
    while (pos != std::string::npos) {
        std::cout << "Pos at " << pos << std::endl;
        pos = text.find(TO_FIND, ++pos);
    }
    return 0;
}
