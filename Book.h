#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;
    bool availability;
    string dateAdded;

public:
    // default + full constructors (lets you use arrays OR direct creation)
    Book() : title(""), author(""), ISBN(""), availability(true), dateAdded("") {}
    Book(string t, string a, string i, bool avail, string date)
        : title(t), author(a), ISBN(i), availability(avail), dateAdded(date) {}

    void setBookDetails(string t, string a, string i, bool avail, string date);
    void displayBookDetails() const;

    // getters used for sorting
    string getTitle()  const { return title; }
    string getISBN()   const { return ISBN;  }
    bool   isAvailable() const { return availability; }

    // simple borrow/return used in A2
    void borrowBook();
    void returnBook();
};

#endif
