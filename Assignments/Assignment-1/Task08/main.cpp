#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    long long paise = 0;
    while (true) {
        if (std::cin >> paise && paise >= 0) break;
        std::cout << "Invalid input ignored.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Accepted Balance: Rs " << paise / 100 << '.' << std::setw(2) << std::setfill('0') << paise % 100 << "\n";
    return 0;
}
