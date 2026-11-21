#include <iostream>
#include <string>

class SmartCard {
    std::string cardId;
    long long balancePaise;
public:
    SmartCard(std::string id, long long bal) : cardId(id), balancePaise(bal) {}
    bool canTravel(long long fare) const { return (balancePaise - fare) >= 5000; }
    void deduct(long long fare) { if (canTravel(fare)) balancePaise -= fare; }
    long long balance() const { return balancePaise; }
};

int main() {
    std::string id;
    long long bal;
    if (!(std::cin >> id >> bal)) { id = "METRO-101"; bal = 10000; }
    SmartCard c(id, bal);
    std::cout << "Card " << id << " initialized with Rs " << c.balance() / 100 << "\n";
    return 0;
}
