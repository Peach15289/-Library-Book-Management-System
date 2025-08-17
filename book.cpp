#include "Book.h"

void Book::setBookDetails(string t, string a, string i, bool avail, string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

void Book::displayBookDetails() const {
    cout << "Title: " << title << "\n"
         << "Author: " << author << "\n"
         << "ISBN: " << ISBN << "\n"
         << "Availability: " << (availability ? "Yes" : "No") << "\n"
         << "Date Added: " << dateAdded << "\n"
         << "-----------------------------\n";
}

void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book borrowed successfully.\n";
    } else {
        cout << "This book is currently not available.\n";
    }
}

void Book::returnBook() {
    availability = true;
    cout << "Book returned successfully.\n";
}
