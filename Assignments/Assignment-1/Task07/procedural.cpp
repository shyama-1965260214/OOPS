#include <iostream>
bool deduct(long long& bal, long long fare) {
    if (bal - fare < 5000) return false;
    bal -= fare;
    return true;
}
int main() {
    long long bal = 8000;
    std::cout << "Procedural deduct Rs 20: " << deduct(bal, 2000) << ", Rem: " << bal/100 << "\n";
    return 0;
}
