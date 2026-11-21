#include <iostream>
#include <cmath>
class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};
inline int minutesBetween(const Time& a, const Time& b) {
    return std::abs((a.h * 60 + a.m) - (b.h * 60 + b.m));
}
inline bool earlier(const Time& a, const Time& b) {
    return (a.h * 60 + a.m) < (b.h * 60 + b.m);
}
int main() {
    int h1, m1, h2, m2;
    std::cin >> h1 >> m1 >> h2 >> m2;
    Time departure(h1, m1), arrival(h2, m2);
    std::cout << minutesBetween(departure, arrival) << ' ' << std::boolalpha << earlier(arrival, departure) << '\n';
}
