#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User {
public:
    // Constructor
    User(std::string name, std::string email);

    // Getters
    std::string getName() const;
    std::string getEmail() const;

    // Borrow/Return Books
    void borrowBook(int bookID);
    void returnBook(int bookID);

    // Display borrowed books
    void displayBorrowedBooks() const;

private:
    std::string name;
    std::string email;
    std::vector<int> borrowedBooks; // List of IDs of borrowed books
};

#endif // USER_H
