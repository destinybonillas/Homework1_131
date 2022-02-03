#include <iostream>
#include <vector>

#include "Book.hpp"

int main() {
    Book b;

    // Read book from standard input until end of file
    std::cin >> b;

    // store book in dynamilcally created object
    Book * newB = new Book;

    // store book pointer in standard vector
    // std::vector<Book> books = *newB;
    // books.push_back(newB);

    // once reached end of file, write books to standard output in reverse order

    // release dynamic memory
    delete newB;
    newB = nullptr;
    return 0;
}
