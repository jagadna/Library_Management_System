#include <iostream>
#include "Library.h"

int main() {
    Library library;

    int choice;
    while (true) {
        std::cout << "Library Management System\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Register User\n";
        std::cout << "3. Borrow Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. List All Books\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.registerUser();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                library.listBooks();
                break;
            case 0:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
