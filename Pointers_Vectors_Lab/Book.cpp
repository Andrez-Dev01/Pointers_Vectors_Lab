#include "Book.h"

#include <iostream>

Book::Book(std::string title, std::string author, double price) {
    this->title = title;
    this->author = author;
    this->price = price;
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Price: $" << price << std::endl;
}
