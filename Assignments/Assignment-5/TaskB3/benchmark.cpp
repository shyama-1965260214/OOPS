#include <iostream>
#include <vector>

struct PodBill { int type; double a, b, c; };
double podTotal(const PodBill& p) {
    switch (p.type) {
        case 0: return p.a + p.b;
        default: return p.a * p.b + p.c;
    }
}

int main() {
    int n = 1000000;
    std::cin >> n;
    std::vector<PodBill> pods(n, {0, 500, 1200, 0});
    double s1 = 0;
    for (const auto& p : pods) s1 += podTotal(p);
    std::cout << "Processed " << n << " bills, Sum: " << s1 << "\n";
    return 0;
}
