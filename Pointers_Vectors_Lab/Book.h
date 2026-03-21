#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    double price;

public:
    Book(std::string title, std::string author, double price);
    void displayInfo() const;
};

#endif