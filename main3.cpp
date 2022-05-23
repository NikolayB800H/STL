#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <sys/stat.h>

constexpr char is_name[] =  "in.txt";
constexpr char os_name[] = "out.txt";

size_t fileSize(const char *f_name) {
    struct stat stat_buf;
    int rc = stat(f_name, &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

void replace(std::string &str, char old_ch, char new_ch) {
    size_t pos = str.find(old_ch);
    while (pos != std::string::npos) {
        str[pos] = new_ch;
        pos = str.find(old_ch, ++pos);
    }
}

int main(int argc, char const *argv[]) {
    std::ifstream is(is_name);
    std::ofstream os(os_name);
    if (!is || !os) {
        std::cout << "File error!" << std::endl;
        return 0;
    }
    size_t size = fileSize(is_name);
    char *text(new char[size + 1]);
    std::fill(text, text + size + 1, 0);
    is.read(text, size);
    if (is.fail()) {
        std::cout << "Read error!" << std::endl;
        return 0;
    }
    std::string str(text);
    delete[] text;
    char old_ch = 0;
    char new_ch = 0;
    std::cout << "Old char = ";
    std::cin.get(old_ch);
    std::cin.ignore(1, '\n');
    std::cout << "\nNew char = ";
    std::cin.get(new_ch);
    std::cin.ignore(1, '\n');
    replace(str, old_ch, new_ch);
    os << str;
    is.close();
    os.close();
    std::cout << std::endl;
    return 0;
}
