#include <iostream>
int main() {
    int a{7}, b{2};
    std::cin >> a >> b;
    double c = static_cast<double>(a) / b;
    int s{-1}, u{1};
    std::cout << "Safe division: " << c << ", Safe signed compare: " << (s < u) << "\n";
    return 0;
}
