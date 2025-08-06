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
        cout << "-----------------------------" << endl;
    }

    string getISBN() {
        return ISBN;
    }

    bool isAvailable() {
        return availability;
    }

    void borrowBook() {
        if (availability) {
            availability = false;
            cout << "Book borrowed successfully.\n";
        } else {
            cout << "This book is currently not available.\n";
        }
    }

    void returnBook() {
        availability = true;
        cout << "Book returned successfully.\n";
    }
};

int main() {
    const int SIZE = 5;
    Book books[SIZE];

    // Initialize 5 books
    books[0].setBookDetails("C++ Basics", "John Smith", "1001", true, "2023-01-01");
    books[1].setBookDetails("OOP Concepts", "Alice Green", "1002", true, "2023-02-15");
    books[2].setBookDetails("Data Structures", "Bob White", "1003", true, "2023-03-10");
    books[3].setBookDetails("Algorithms", "Sara Black", "1004", true, "2023-04-05");
    books[4].setBookDetails("Design Patterns", "Tom Grey", "1005", true, "2023-05-20");

    string userISBN;

    while (true) {
        cout << "\n--- Available Books ---\n";
        for (int i = 0; i < SIZE; i++) {
            books[i].displayBookDetails();
        }

        cout << "\nEnter ISBN to borrow a book (Enter 0 to exit): ";
        cin >> userISBN;

        if (userISBN == "0") {
            cout << "Exiting the system.\n";
            break;
        }

        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (books[i].getISBN() == userISBN) {
                found = true;
                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                } else {
                    cout << "Error: Book is already borrowed.\n";
                }
                break;
            }
        }

        if (!found) {
            cout << "Error: Book not found.\n";
        }
    }

    return 0;
}
