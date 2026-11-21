#include <iostream>

enum class Zone { Inner = 0, Middle = 1, Outer = 2, Airport = 3 };
constexpr long long FARE_TABLE[] = {1000, 2000, 3000, 6000};

class MonthlyPass {
    Zone z1, z2;
    bool active;
public:
    MonthlyPass(Zone a, Zone b, bool act) : z1(a), z2(b), active(act) {}
    bool covers(Zone z) const { return active && (z == z1 || z == z2); }
};

long long computeFare(Zone z, bool peak, bool weekend, const MonthlyPass& pass) {
    if (pass.covers(z)) return 0;
    long long f = FARE_TABLE[static_cast<int>(z)];
    if (weekend) return f - (f * 10) / 100;
    if (peak) return f + (f * 20) / 100;
    return f;
}

int main() {
    MonthlyPass p(Zone::Inner, Zone::Middle, true);
    int z, peak, weekend;
    while (std::cin >> z >> peak >> weekend) {
        std::cout << "Fare Rs: " << computeFare(static_cast<Zone>(z), peak, weekend, p) / 100 << "\n";
    }
    return 0;
}
