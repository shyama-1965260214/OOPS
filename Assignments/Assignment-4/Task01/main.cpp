#include <iostream>
#include <string>

class Staff {
protected:
    std::string name;
    int id;
    static constexpr double DA_RATE = 0.42;
public:
    Staff(std::string n, int i) : name(std::move(n)), id(i) {}
    virtual ~Staff() = default;
    virtual double pay() const = 0;
    std::string getName() const { return name; }
};

class Professor : public Staff {
    double basic, research;
public:
    Professor(std::string n, int i, double b, double r) : Staff(std::move(n), i), basic(b), research(r) {}
    double pay() const override { return basic + basic * DA_RATE + research; }
};

int main() {
    std::string n; double b, r;
    std::cin >> n >> b >> r;
    Professor p(n, 1, b, r);
    std::cout << p.getName() << " Pay: Rs " << p.pay() << "\n";
    return 0;
}
