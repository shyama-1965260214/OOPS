#include <iostream>
#include <iomanip>

int main() {
    long long n = 3000000LL;
    std::cin >> n;
    long long exactPaise = 0;
    double approxRupees = 0.0;
    for (long long i = 0; i < n; ++i) {
        exactPaise += 1200;
        approxRupees += 12.00;
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Journeys: " << n << " | Exact (Rs): " << exactPaise / 100.0 << " | Double (Rs): " << approxRupees << "\n";
    return 0;
}
