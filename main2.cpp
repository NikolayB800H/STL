#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::string text;
    getline(std::cin, text, '\n');
    size_t size = text.size();
    size_t i = 1;
    for (; i * 2 < size; ++i) {
        text[i] = text[i * 2];
    }
    text.resize(i);
    std::cout << text << std::endl;
    return 0;
}
