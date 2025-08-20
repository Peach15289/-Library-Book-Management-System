#include <algorithm>
#include <iostream>
#include "Book.h"

// ---------- helpers ----------
void divider(const std::string& title) {
    std::cout << "\n==================== " << title << " ====================\n";
}

void showArray(const std::string& label, Book a[], int n) {
    std::cout << "\n" << label << "\n";
    for (int i = 0; i < n; ++i) a[i].displayBookDetails();
}

void sortAsc(Book a[], int n) {
    std::sort(a, a + n, [](const Book& x, const Book& y) {
        return x.getTitle() < y.getTitle();
    });
}

void sortDesc(Book a[], int n) {
    std::sort(a, a + n, [](const Book& x, const Book& y) {
        return x.getTitle() > y.getTitle();
    });
}

// ---------- main ----------
int main() {
    // ----- Correct book information (as per brief) -----
    Book b1, b2, b3;
    b1.setBookDetails("C++ Basics",     "John Smith",  "1001", true,  "2023-01-01");
    b2.setBookDetails("OOP Concepts",   "Alice Green", "1002", true,  "2023-02-15");
    b3.setBookDetails("Data Structures","Bob White",   "1003", false, "2023-03-10");

    divider("Evidence: Correct book information initialisation");
    Book correct[3] = { b1, b2, b3 };
    showArray("Correct Books:", correct, 3);

    // ----- Incorrect book information (negative tests) -----
    Book bad1, bad2, bad3;
    bad1.setBookDetails("12345",       "Unknown",   "ISBN-000", true,  "Aug 40, 2025");
    bad2.setBookDetails("No Title",    "9876",      "ISBN-111", true,  "32/13/2025");
    bad3.setBookDetails("Broken Data", "No Author", "INVALID",  false, "Not a Date");

    divider("Evidence: Incorrect book information initialisation");
    Book incorrect[3] = { bad1, bad2, bad3 };
    showArray("Incorrect Books (for negative tests):", incorrect, 3);

    // ----- Build three input arrays by TITLE order -----
    // Titles: "C++ Basics", "Data Structures", "OOP Concepts"
    Book ascInput[3]   = { b1, b3, b2 }; // ASC by title
    Book descInput[3]  = { b2, b3, b1 }; // DESC by title
    Book mixedInput[3] = { b3, b1, b2 }; // MIXED

    // ===== Sort to ASC evidence =====
    divider("ASC input -> sort to ASC");
    showArray("Before (ASC input):", ascInput, 3);
    sortAsc(ascInput, 3);
    showArray("After  (ASC result):", ascInput, 3);

    divider("DESC input -> sort to ASC");
    showArray("Before (DESC input):", descInput, 3);
    sortAsc(descInput, 3);
    showArray("After  (ASC result):", descInput, 3);

    divider("MIXED input -> sort to ASC");
    showArray("Before (MIXED input):", mixedInput, 3);
    sortAsc(mixedInput, 3);
    showArray("After  (ASC result):", mixedInput, 3);

    // Rebuild inputs for DESC run (so we start from original orders again)
    Book ascInput2[3]   = { b1, b3, b2 };
    Book descInput2[3]  = { b2, b3, b1 };
    Book mixedInput2[3] = { b3, b1, b2 };

    // ===== Sort to DESC evidence =====
    divider("ASC input -> sort to DESC");
    showArray("Before (ASC input):", ascInput2, 3);
    sortDesc(ascInput2, 3);
    showArray("After  (DESC result):", ascInput2, 3);

    divider("DESC input -> sort to DESC");
    showArray("Before (DESC input):", descInput2, 3);
    sortDesc(descInput2, 3);
    showArray("After  (DESC result):", descInput2, 3);

    divider("MIXED input -> sort to DESC");
    showArray("Before (MIXED input):", mixedInput2, 3);
    sortDesc(mixedInput2, 3);
    showArray("After  (DESC result):", mixedInput2, 3);

    std::cout << "\nAll tests complete.\n";
    return 0;
}
