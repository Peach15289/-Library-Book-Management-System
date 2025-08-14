#include <iostream>
#include <vector>
#include "bookait.h"

using namespace std;

int main() {
    Book b1, b2, b3;
    b1.setBookDetails("C++ Basics", "John Smith", "1001", true, "2023-01-01");
    b2.setBookDetails("OOP Concepts", "Alice Green", "1002", true, "2023-02-15");
    b3.setBookDetails("Data Structures", "Bob White", "1003", true, "2023-03-10");

    vector<Book> asc   = { b1, b2, b3 };
    vector<Book> desc  = { b3, b2, b1 };
    vector<Book> mixed = { b2, b1, b3 };

    cout << "\n===== ASC input → sort to ASC =====\nBefore Sorting:\n";
    printBooks(asc);
    sortBooksByISBN(asc, true);
    cout << "After Sorting:\n";
    printBooks(asc);

    string userISBN;
    while (true) {
        cout << "\n--- Borrow a Book by ISBN (Enter 0 to exit) ---\n";
        cout << "Available books:\n";
        for (const auto& book : asc) book.displayBookDetails();

        cout << "Enter ISBN: ";
        cin >> userISBN;
        if (userISBN == "0") break;

        bool found = false;
        for (auto& book : asc) {
            if (book.getISBN() == userISBN) {
                found = true;
                book.borrowBook();
                break;
            }
        }
        if (!found) cout << "Error: Book not found.\n";
    }

    cout << "Exiting library system.\n";
    return 0;
}
