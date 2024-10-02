#include "Library.h"
#include "Database.h"
#include <iostream>


// Constructor
Library::Library() {}

// Add a book to the library
void Library::addBook() {
    std::string title, author, isbn;
    int year;

    std::cout << "Enter Book Title: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter Author: ";
    std::getline(std::cin, author);
    std::cout << "Enter ISBN: ";
    std::getline(std::cin, isbn);
    std::cout << "Enter Year: ";
    std::cin >> year;

    auto book = std::make_shared<Book>(title, author, isbn, year);
    books.push_back(book);

    // Add to the database
    addBookToDatabase(*book);
}

// Register a new user
void Library::registerUser() {
    std::string name, email;

    std::cout << "Enter User Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    auto user = std::make_shared<User>(name, email);
    users.push_back(user);

    // Add to the database
    addUserToDatabase(*user);
}

// Borrow a book
void Library::borrowBook() {
    std::string isbn, userName;

    std::cout << "Enter User Name: ";
    std::cin.ignore();
    std::getline(std::cin, userName);
    std::cout << "Enter Book ISBN: ";
    std::getline(std::cin, isbn);

    for (auto& book : books) {
        if (book->getISBN() == isbn && book->isAvailable()) {
            for (auto& user : users) {
                if (user->getName() == userName) {
                    book->setAvailable(false);
                    user->borrowBook(book->getYear()); // Using year as a placeholder for book ID
                    std::cout << "Book borrowed successfully!\n";
                    return;
                }
            }
        }
    }
    std::cout << "Book or User not found, or Book not available.\n";
}

// Return a book
void Library::returnBook() {
    std::string isbn, userName;

    std::cout << "Enter User Name: ";
    std::cin.ignore();
    std::getline(std::cin, userName);
    std::cout << "Enter Book ISBN: ";
    std::getline(std::cin, isbn);

    for (auto& book : books) {
        if (book->getISBN() == isbn && !book->isAvailable()) {
            for (auto& user : users) {
                if (user->getName() == userName) {
                    book->setAvailable(true);
                    user->returnBook(book->getYear()); // Using year as a placeholder for book ID
                    std::cout << "Book returned successfully!\n";
                    return;
                }
            }
        }
    }
    std::cout << "Book or User not found.\n";
}

// List all books
void Library::listBooks() const {
    if (books.empty()) {
        std::cout << "No books available in the library.\n";
    } else {
        for (const auto& book : books) {
            book->displayDetails();
            std::cout << "-------------------------\n";
        }
    }
}

// Add a book to the database
void Library::addBookToDatabase(const Book& book) {
    Database db("data/library.db");
    std::string sql = "INSERT INTO books (title, author, isbn, year) VALUES ('" +
                      book.getTitle() + "', '" + book.getAuthor() + "', '" +
                      book.getISBN() + "', " + std::to_string(book.getYear()) + ");";
    char* errorMessage = nullptr;
    if (!db.executeSQL(sql, &errorMessage)) {
        std::cerr << "Error adding book to database: " << errorMessage << std::endl;
    }
}

// Add a user to the database
void Library::addUserToDatabase(const User& user) {
    Database db("data/library.db");
    std::string sql = "INSERT INTO users (name, email) VALUES ('" +
                      user.getName() + "', '" + user.getEmail() + "');";
    char* errorMessage = nullptr;
    if (!db.executeSQL(sql, &errorMessage)) {
        std::cerr << "Error adding user to database: " << errorMessage << std::endl;
    }
}
