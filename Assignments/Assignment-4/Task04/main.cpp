#include <iostream>
#include <vector>
#include <memory>
class Account {
public:
    virtual double rate() const { return 3.5; }
    virtual ~Account() = default;
};
class SeniorAccount : public Account {
    double* history = new double[100];
public:
    double rate() const override { return 4.0; }
    ~SeniorAccount() override { delete[] history; }
};
int main() {
    int type;
    std::vector<std::unique_ptr<Account>> accounts;
    while (std::cin >> type) {
        if (type == 0) accounts.push_back(std::make_unique<Account>());
        else accounts.push_back(std::make_unique<SeniorAccount>());
    }
    for (const auto& a : accounts) std::cout << "Rate: " << a->rate() << "%\n";
    return 0;
}
