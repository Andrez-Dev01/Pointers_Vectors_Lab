/*Andrez De La Torre
 * 3/08/2026
 * MCSCI - 272
 * Lab: Pointers
*/

#include <iostream>
#include <vector>
#include <string>

class Book {
    private:
        std::string title;
        std::string author;
        double price;
        
    public:
        Book();
        Book(std::string title, std::string author, double price);
        void displayInfo() const;

};

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

Inventory::~Inventory() {
    for (int i = 0; i < books.size(); ++i) {
        delete books[i];
    }
}

void Inventory::addBook(Book* bookPtr) {
    books.push_back(bookPtr);
}

void Inventory::displayAll() const {
    for (int i = 0; i < books.size(); ++i) {
        books[i]->displayInfo();
    }
}

void Inventory::removeBook(int index) {
    if (index >= 0 && index < books.size()) {
        delete books[index];
        books.erase(books.begin() + index);
        std::cout << "Book removed successfully." << std::endl;
    } else {
        std::cout << "Invalid index. Book not removed." << std::endl;
    }
}


int main() {

    Inventory inventory;

    do {
        std::cout << "1. Add a book" << std::endl;
        std::cout << "2. Display all books" << std::endl;
        std::cout << "3. Remove a book" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::string title, author;
                double price;
                std::cout << "Enter the title of the book: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter the author of the book: ";
                std::getline(std::cin, author);
                std::cout << "Enter the price of the book: ";
                std::cin >> price;
                Book* bookPtr = new Book(title, author, price);
                break;
            case 2:
                inventory.displayAll();
                break;
            case 3:
                removeBook(inventory);
                break;
            case 4:
                std::cout << "Exiting program..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);
    
    std::cout << "Program ended." << std::endl;
    return 0;
}