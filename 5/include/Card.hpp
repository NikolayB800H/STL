#pragma once

#include <fstream>
#include <string>

class Card {
public:
    Card();
    Card(std::string const &t, std::string const &a, int n);
    bool isByAuthor(std::string const &str) const;
    friend std::ostream &operator<<(std::ostream &os, Card const &card);
private:
    std::string title; 
    std::string author;
    int number;
};
