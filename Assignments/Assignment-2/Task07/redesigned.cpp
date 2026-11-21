#include <iostream>
template <int CAP>
class RingStatement {
    double tx[CAP];
    int head = 0, count = 0;
public:
    void add(double v) {
        tx[(head + count) % CAP] = v;
        if (count < CAP) ++count;
        else head = (head + 1) % CAP;
    }
    int size() const { return count; }
};
int main() {
    int inserts = 100;
    std::cin >> inserts;
    RingStatement<50> s;
    for (int i = 0; i < inserts; ++i) s.add(i);
    std::cout << "O(1) RingBuffer<50> active entries: " << s.size() << "\n";
    return 0;
}
