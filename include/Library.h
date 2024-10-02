#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include "User.h"
#include <vector>
#include <memory>

class Library {
public:
    // Constructor
    Library();

    // Book Management
    void addBook();
    void removeBook();
    void listBooks() const;

    // User Management
    void registerUser();
    void listUsers() const;

    // Borrow/Return Operations
    void borrowBook();
    void returnBook();

    // Database related methods
    void addBookToDatabase(const Book& book);
    void addUserToDatabase(const User& user);

private:
    std::vector<std::shared_ptr<Book>> books; // List of books in the library
    std::vector<std::shared_ptr<User>> users; // List of registered users
};

#endif // LIBRARY_H
