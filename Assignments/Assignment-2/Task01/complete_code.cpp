#include <iostream>
void applyByValue(long long fee, int percent) { fee -= fee * percent / 100; }
void applyConcession(long long& fee, int percent) { fee -= fee * percent / 100; }
int main() {
    long long hostelFee = 45000;
    int pct = 10;
    std::cin >> hostelFee >> pct;
    applyByValue(hostelFee, pct);
    std::cout << "after call by value	: " << hostelFee << '\n';
    applyConcession(hostelFee, pct);
    std::cout << "after call by reference: " << hostelFee << '\n';
}
