#include <iostream>
#include <fstream>
#include "bookait.h"

int main() {
    std::vector<Book> books = {
        Book("C++ Basics", "John Smith", "1001", true, "2023-01-01"),
        Book("OOP Concepts", "Alice Green", "1002", true, "2023-02-15"),
        Book("Data Structures", "Bob White", "1003", true, "2023-03-10")
    };

    std::ofstream outFile("library_sort_results.txt");

    // Before Sorting
    outFile << "=== BEFORE SORTING (Original Order) ===\n";
    printBooks(books, outFile);

    // ASCENDING Sort
    sortBooksByISBN(books, true);
    outFile << "=== AFTER SORTING (Ascending by ISBN) ===\n";
    printBooks(books, outFile);

    // DESCENDING Sort
    sortBooksByISBN(books, false);
    outFile << "=== AFTER SORTING (Descending by ISBN) ===\n";
    printBooks(books, outFile);

    outFile.close();

    std::cout << "Results saved to library_sort_results.txt\n";
    return 0;
}
