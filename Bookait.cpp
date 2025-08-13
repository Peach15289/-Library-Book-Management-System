#include "bookait.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Book::setBookDetails(const string& t, const string& a, const string& i, bool avail, const string& date) {
    title = t;
    author = a;
    ISBN = i;
    availability = avail;
    dateAdded = date;
}

void Book::displayBookDetails() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Available: " << (availability ? "Yes" : "No") << endl;
    cout << "Date Added: " << dateAdded << endl;
    cout << "-----------------------------" << endl;
}

string Book::getISBN() const { return ISBN; }
bool Book::isAvailable() const { return availability; }

void Book::borrowBook() {
    if (availability) {
        availability = false;
        cout << "Book \"" << title << "\" borrowed successfully.\n";
    } else {
        cout << "Book \"" << title << "\" is currently not available.\n";
    }
}

void Book::returnBook() {
    availability = true;
    cout << "Book \"" << title << "\" returned successfully.\n";
}

void printBooks(const vector<Book>& books) {
    for (const auto& book : books) {
        book.displayBookDetails();
    }
}

void sortBooksByISBN(vector<Book>& books, bool ascending) {
    sort(books.begin(), books.end(), [ascending](const Book& a, const Book& b) {
        return ascending ? a.getISBN() < b.getISBN() : a.getISBN() > b.getISBN();
    });
}

