#include <iostream>
#include <cmath>
#include <stdexcept>

class Complex {
    double re, im;
public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}
    Complex operator+(const Complex& o) const { return {re + o.re, im + o.im}; }
    Complex operator*(const Complex& o) const { return {re*o.re - im*o.im, re*o.im + im*o.re}; }
    Complex operator/(const Complex& o) const {
        double d = o.re*o.re + o.im*o.im;
        if (d == 0.0) throw std::domain_error("Division by zero");
        return {(re*o.re + im*o.im)/d, (im*o.re - re*o.im)/d};
    }
    double mag() const { return std::hypot(re, im); }
    friend std::ostream& operator<<(std::ostream& os, const Complex& z) {
        return os << z.re << (z.im >= 0 ? " + " : " - ") << std::abs(z.im) << "j";
    }
};

int main() {
    double r1, i1, r2, i2;
    std::cin >> r1 >> i1 >> r2 >> i2;
    Complex Z1(r1, i1), Z2(r2, i2);
    Complex Zs = Z1 + Z2;
    Complex Zp = (Z1 * Z2) / (Z1 + Z2);
    std::cout << "Series: " << Zs << " | Parallel: " << Zp << "\n";
    return 0;
}
