#include <iostream>

enum class Zone { Inner = 0, Middle = 1, Outer = 2 };
constexpr long long BASE_FARE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PCT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

int main() {
    int z = 0;
    std::cin >> z;
    std::cout << "Base Fare: Rs " << BASE_FARE_PAISE[z] / 100 << ", Min Bal: Rs " << MIN_BALANCE_PAISE / 100 << "\n";
    return 0;
}
