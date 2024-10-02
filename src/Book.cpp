#include "Book.h"
#include <iostream>

// Constructor
Book::Book(std::string title, std::string author, std::string isbn, int year)
    : title(title), author(author), isbn(isbn), year(year), available(true) {}

// Getters
std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

int Book::getYear() const {
    return year;
}

bool Book::isAvailable() const {
    return available;
}

// Setters
void Book::setAvailable(bool status) {
    available = status;
}

// Display book details
void Book::displayDetails() const {
    std::cout << "Title: " << title << "\nAuthor: " << author 
              << "\nISBN: " << isbn << "\nYear: " << year 
              << "\nAvailable: " << (available ? "Yes" : "No") << "\n";
}
