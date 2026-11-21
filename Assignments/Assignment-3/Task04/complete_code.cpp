#include <iomanip>
#include <iostream>
#include <cstdlib>
class Money {
    long long paise;
public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}
    Money operator+(const Money& rhs) const { return Money(0, paise + rhs.paise); }
    bool operator==(const Money& rhs) const { return paise == rhs.paise; }
    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        return os << "Rs " << m.paise / 100 << '.' << std::setw(2) << std::setfill('0') << std::abs(m.paise % 100);
    }
};
int main() {
    long long r1, r2; int p1, p2;
    std::cin >> r1 >> p1 >> r2 >> p2;
    Money a(r1, p1), b(r2, p2);
    Money c = a + b;
    std::cout << c << '\n' << std::boolalpha << (c == Money(200)) << '\n';
}
