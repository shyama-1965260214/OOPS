#include <iostream>
class SavingsAccount {
    int accNo;
    double balance;
    double tx[10];
    int count = 0, head = 0;
    void record(double amt) {
        tx[(head + count) % 10] = amt;
        if (count < 10) ++count;
        else head = (head + 1) % 10;
    }
public:
    SavingsAccount(int no, double bal) : accNo(no), balance(bal) {}
    void deposit(double amt) { balance += amt; record(amt); }
    void miniStatement() const {
        std::cout << "Count: " << count << ", Bal: " << balance << ", Latest: " << tx[(head + count - 1) % 10] << "\n";
    }
};
int main() {
    int n; std::cin >> n;
    SavingsAccount s(1001, 5000);
    for (int i = 1; i <= n; ++i) s.deposit(i * 100);
    s.miniStatement();
    return 0;
}
