#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Book.h"

class Inventory {
private:
    std::vector<Book*> books;

public:
    Inventory();
    void addBook(Book* bookPtr);
    void displayAll() const;
    void removeBook(int index);
    ~Inventory();
};

#endif