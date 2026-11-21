#include <iostream>
class SmartCard {
    long long balance;
public:
    explicit SmartCard(long long b) : balance(b >= 0 ? b : 0) {}
    bool canTravel(long long fare) const { return (balance - fare) >= 5000; }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }
    long long getBalance() const { return balance; }
};
int main() {
    long long initBal = 8000, fare = 2000;
    std::cin >> initBal >> fare;
    SmartCard card(initBal);
    std::cout << "OOP deduct: " << card.deduct(fare) << ", Rem Rs: " << card.getBalance() / 100 << "\n";
    return 0;
}
