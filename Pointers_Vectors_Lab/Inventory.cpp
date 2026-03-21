#include "Inventory.h"
#include <iostream>

Inventory::Inventory() {}

void Inventory::addBook(Book* bookPtr) {
    books.push_back(bookPtr);
}

void Inventory::displayAll() const {
    if (books.empty()) {
        std::cout << "No books in inventory." << std::endl;
        return;
    }

    for (Book* book : books) {
        book->displayInfo();
        std::cout << std::endl;
    }
}

void Inventory::removeBook(int index) {
    if (index >= 0 && index < static_cast<int>(books.size())) {
        delete books[index];
        books.erase(books.begin() + index);
        std::cout << "Book removed successfully." << std::endl;
    } else {
        std::cout << "Invalid index. Book not removed." << std::endl;
    }
}

Inventory::~Inventory() {
    for (Book* book : books) {
        delete book;
    }
}
