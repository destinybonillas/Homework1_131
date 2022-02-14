#include <iomanip>   // needed for setprecision
#include <iostream>  // needed for showpoint() && fixed()
#include <memory>    // needed for unique_ptr
#include <utility>   // needed for move()
#include <vector>  

#include "Book.hpp"  // needed to use contents from book class

int main() {


    // Start w/ a welcome message
                // showpoint, fixed, setprecision can be used this early on to ensure
                // decimal point is shown on price numbers -- move later if still confused
    std::cout << std::showpoint << std::fixed << std::setprecision(2)
              << "Welcome to Forgotten Books! This is a bookstore "
              << " filled with books from all around! Please place your books into "
              << " your shopping cart.\n"
              << " Enclose string entries with quotes, separate fields with commas.\n"
              << " Enter CTRL-Z for Windows, or CTRL-D for Linux to quit\n\n";


    // store book pointer in standard vector
    std::vector<std::unique_ptr<Book>> shoppingCart;

    // Create a book
    Book b;

    // Read book until end of file
    while (std::cout << " Enter ISBN, Title, Author, and Price\n", std::cin >> b)
    {
        // Place here what you are going to read, in this case you want to read b,
        // so you fill b w/ books from shoppingCart
        shoppingCart.push_back(std::make_unique<Book> (std::move(b))); // this is moves contents
        std::cout << "Item(s) added to shopping cart: " << *shoppingCart.back() << "\n\n";
    }


    // once reached end of file, write books to standard output in reverse order
    std::cout << "\n\n Here is an itemized list of the items in your shopping cart: \n";
    for (unsigned i = 0; i < shoppingCart.size(); i++) std::cout << *shoppingCart[i] << std::endl;


    return 0;
}
