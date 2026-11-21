#include <iostream>

enum class Zone { Inner, Middle, Outer };
bool isPeak(int h) { return (h >= 8 && h < 10) || (h >= 17 && h < 20); }
long long calcFare(Zone z, int h) {
    long long b = (z == Zone::Inner) ? 1000 : (z == Zone::Middle ? 2000 : 3000);
    return isPeak(h) ? b + b * 20 / 100 : b;
}
int main() {
    int z, h;
    while (std::cin >> z >> h) {
        std::cout << "Zone " << z << " Hour " << h << " -> Paise: " << calcFare(static_cast<Zone>(z), h) << "\n";
    }
    return 0;
}
