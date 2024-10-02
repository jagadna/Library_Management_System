#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    // Constructor
    Book(std::string title, std::string author, std::string isbn, int year);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getISBN() const;
    int getYear() const;
    bool isAvailable() const;

    // Setters
    void setAvailable(bool status);

    // Display details
    void displayDetails() const;

private:
    std::string title;
    std::string author;
    std::string isbn;
    int year;
    bool available; // true if book is available for borrowing, false otherwise
};

#endif // BOOK_H
