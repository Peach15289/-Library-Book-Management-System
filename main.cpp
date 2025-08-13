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
    void setBookDetails(string t, string a, string i, bool avail, string date) {
        title = t;
        author = a;
        ISBN = i;
        availability = avail;
        dateAdded = date;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available: " << (availability ? "Yes" : "No") << endl;
        cout << "Date Added: " << dateAdded << endl;
        cout << "-----------------------------" << endl << endl;
    }

    string getISBN() {
        return ISBN;
    }

    bool isAvailable() {
        return availability;
    }

    void borrowBook() {