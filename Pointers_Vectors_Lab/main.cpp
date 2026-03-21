/*Andrez De La Torre
 * 3/08/2026
 * MCSCI - 272
 * Lab: Pointers
*/

#include <iostream>
#include "Inventory.h"
#include "Book.h"

int main() {
    Inventory store;
    int choice = 0;

    do {
        std::cout << "<------------------------------------------>" << std::endl;
        std::cout << "Welcome to the Book Inventory System!" << std::endl;
        std::cout << "1. Add Book" << std::endl;
        std::cout << "2. Display Inventory" << std::endl;
        std::cout << "3. Remove Book" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "<------------------------------------------>" << std::endl;
                std::cout << "Enter book title: ";
                std::string title;
                std::cin >> title;
                std::cout << "Enter book author: ";
                std::string author;
                std::cin >> author;
                std::cout << "Enter book price: ";
                double price;
                std::cin >> price;
                Book* book = new Book(title, author, price);
                store.addBook(book);
                break;
            }
            case 2: {
                std::cout << "<------------------------------------------>" << std::endl;
                std::cout << "Inventory:" << std::endl;
                store.displayAll();
                break;
            }
            case 3: {
                std::cout << "<------------------------------------------>" << std::endl;
                std::cout << "Enter the index of the book to remove (starting index 0 as your first book): ";
                int index;
                std::cin >> index;
                store.removeBook(index);
                break;
            }
            case 4: {
                std::cout << "<------------------------------------------>" << std::endl;
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default:
                std::cout << "<------------------------------------------>" << std::endl;
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);
    return 0;
}