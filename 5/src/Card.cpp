#include <fstream>
#include <string>

#include "Card.hpp"

Card::Card() : title(""), author(""), number(0) {
}

Card::Card(std::string const &t, std::string const &a, int n): title(t)
                                                             , author(a)
                                                             , number(n) {
}

bool Card::isByAuthor(std::string const &str) const {
    return str == author;
}

std::ostream &operator<<(std::ostream &os, Card const &card) {
    os << "Card{title: " << card.title << ", author: " << card.author << ", number: " << card.number << "}";
    return os;
}
