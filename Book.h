#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool        availability{};
    std::string dateAdded;

public:
    // Set details of a book
    void setBookDetails(std::string t, std::string a, std::string i, bool avail, std::string date);

    // Print book details (evidence output)
    void displayBookDetails() const;

    // Getters used for sorting/comparisons
    const std::string& getTitle()     const { return title; }
    const std::string& getISBN()      const { return ISBN; }
    const std::string& getDateAdded() const { return dateAdded; }
};

#endif
