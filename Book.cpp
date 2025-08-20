#include "Book.h"
#include <iostream>

void Book::setBookDetails(std::string t, std::string a, std::string i, bool avail, std::string date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

void Book::displayBookDetails() const {
    std::cout << "Title: "      << title       << '\n'
              << "Author: "     << author      << '\n'
              << "ISBN: "       << ISBN        << '\n'
              << "Available: "  << (availability ? "Yes" : "No") << '\n'
              << "Date Added: " << dateAdded   << '\n'
              << "---------------------------------------\n";
}
