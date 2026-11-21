#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Vehicle {
protected:
    std::string regNo;
    double dailyRate;
public:
    Vehicle(std::string r, double rate) : regNo(std::move(r)), dailyRate(rate) {}
    virtual ~Vehicle() = default;
    virtual double rentalCharge(int days, double extraUsage) const = 0;
    std::string id() const { return regNo; }
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string r, double rate) : Vehicle(std::move(r), rate) {}
    double rentalCharge(int days, double) const override { return days * dailyRate; }
};

class ElectricCar : public Vehicle {
    double ratePerKwh;
public:
    ElectricCar(std::string r, double rate, double kwhRate) : Vehicle(std::move(r), rate), ratePerKwh(kwhRate) {}
    double rentalCharge(int days, double kwhUsed) const override { return days * dailyRate + kwhUsed * ratePerKwh; }
};

int main() {
    int days; double kwh;
    std::cin >> days >> kwh;
    std::vector<std::unique_ptr<Vehicle>> fleet;
    fleet.push_back(std::make_unique<Bicycle>("CYC-01", 150));
    fleet.push_back(std::make_unique<ElectricCar>("TN01-EV99", 2000, 12));
    for (const auto& v : fleet) std::cout << v->id() << " Charge: Rs " << v->rentalCharge(days, kwh) << "\n";
    return 0;
}
