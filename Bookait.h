#ifndef BOOKAIT_H
#define BOOKAIT_H

#include <string>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool availability;
    std::string dateAdded;

public:
    void setBookDetails(const std::string& t, const std::string& a, const std::string& i, bool avail, const std::string& date);
    void displayBookDetails() const;
    std::string getISBN() const;
    bool isAvailable() const;
    void borrowBook();
    void returnBook();
};

// Helper functions
void printBooks(const std::vector<Book>& books);
void sortBooksByISBN(std::vector<Book>& books, bool ascending = true);

#endif
