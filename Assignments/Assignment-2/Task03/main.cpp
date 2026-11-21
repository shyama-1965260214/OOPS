#include <iostream>
struct Parcel { double kg; bool express; bool insured; };
double charge(double weightKg, bool express = false, bool insured = false) {
    return weightKg * 50.0 + (express ? 100.0 : 0.0) + (insured ? 75.0 : 0.0);
}
double charge(int weightGrams) { return charge(weightGrams / 1000.0); }
double charge(const Parcel& p) { return charge(p.kg, p.express, p.insured); }
int main() {
    double kg; int g;
    std::cin >> kg >> g;
    std::cout << "Kg charge: " << charge(kg) << ", Grams charge: " << charge(g) << "\n";
    return 0;
}
