#include <iostream>
bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
int main() {
    int h;
    while (std::cin >> h) {
        std::cout << "Hour " << h << ": " << (isPeak(h) ? "Peak" : "Off-Peak") << "\n";
    }
    return 0;
}
