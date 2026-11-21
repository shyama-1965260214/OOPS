#include <iostream>
#include <string>
#include <stdexcept>

class Book {
    std::string title, author;
    int copies;
public:
    Book(std::string t, std::string a, int c) : title(std::move(t)), author(std::move(a)), copies(c) {
        if (copies < 0) throw std::invalid_argument("Copies cannot be negative");
    }
    explicit Book(std::string t) : Book(std::move(t), "Unknown", 1) {}
    Book() : Book("Untitled", "Unknown", 0) {}
    void print() const { std::cout << title << " | " << author << " | Copies: " << copies << "\n"; }
};

int main() {
    std::string t, a; int c;
    std::cin >> t >> a >> c;
    Book b1, b2(t), b3(t, a, c);
    b1.print(); b2.print(); b3.print();
    return 0;
}
