#include <iostream>
#include <memory>
#include <vector>

class Bill {
public:
    virtual ~Bill() = default;
    virtual double total() const = 0;
};
class TelemedicineBill : public Bill {
    double fee;
public:
    explicit TelemedicineBill(double f) : fee(f) {}
    double total() const override { return fee; }
};
int main() {
    double fee = 750;
    std::cin >> fee;
    std::vector<std::unique_ptr<Bill>> v;
    v.push_back(std::make_unique<TelemedicineBill>(fee));
    std::cout << "Extended TelemedicineBill Total: Rs " << v[0]->total() << "\n";
    return 0;
}
