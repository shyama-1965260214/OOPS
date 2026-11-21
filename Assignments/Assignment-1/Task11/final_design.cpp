#include <iostream>
constexpr long long FARE_TABLE[] = {1000, 2000, 3000};
int main() {
    int z = 1;
    std::cin >> z;
    std::cout << "Final Design Lookup Paise: " << FARE_TABLE[z] << "\n";
    return 0;
}
