#include <iostream>
#include <string>
#include <stdexcept>
class Time {
    int sec;
public:
    explicit Time(int s = 0) : sec(s) {}
    Time& operator++() { ++sec; return *this; }
    Time operator++(int) { Time t = *this; ++sec; return t; }
    int seconds() const { return sec; }
};
class Playlist {
    std::string tracks[3] = {"Track1", "Track2", "Track3"};
public:
    const std::string& operator[](int i) const {
        if (i < 0 || i >= 3) throw std::out_of_range("Index out of range");
        return tracks[i];
    }
};
int main() {
    int s, idx;
    std::cin >> s >> idx;
    Time t(s); ++t;
    Playlist pl;
    std::cout << "Seconds: " << t.seconds() << ", Selected: " << pl[idx] << "\n";
    return 0;
}
