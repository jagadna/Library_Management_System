#include "User.h"
#include <iostream>
#include <algorithm>

// Constructor
User::User(std::string name, std::string email)
    : name(name), email(email) {}

// Getters
std::string User::getName() const {
    return name;
}

std::string User::getEmail() const {
    return email;
}

// Borrow a book
void User::borrowBook(int bookID) {
    borrowedBooks.push_back(bookID);
}

// Return a book
void User::returnBook(int bookID) {
    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookID), 
        borrowedBooks.end()
    );
}

// Display borrowed books
void User::displayBorrowedBooks() const {
    std::cout << "Borrowed Books: ";
    if (borrowedBooks.empty()) {
        std::cout << "None\n";
    } else {
        for (int bookID : borrowedBooks) {
            std::cout << bookID << " ";
        }
        std::cout << "\n";
    }
}
