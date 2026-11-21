#include <iostream>
#include <cstring>
#include <string>

class Text {
    std::size_t len;
    char* buf;
public:
    Text(const char* s = "") : len(std::strlen(s)), buf(new char[len + 1]) {
        std::memcpy(buf, s, len + 1);
    }
    Text(const Text& o) : len(o.len), buf(new char[len + 1]) {
        std::memcpy(buf, o.buf, len + 1);
    }
    Text& operator=(const Text& o) {
        if (this == &o) return *this;
        char* nb = new char[o.len + 1];
        std::memcpy(nb, o.buf, o.len + 1);
        delete[] buf;
        buf = nb;
        len = o.len;
        return *this;
    }
    ~Text() { delete[] buf; }
    Text operator+(const Text& rhs) const {
        Text res;
        delete[] res.buf;
        res.len = len + rhs.len;
        res.buf = new char[res.len + 1];
        std::memcpy(res.buf, buf, len);
        std::memcpy(res.buf + len, rhs.buf, rhs.len + 1);
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const Text& t) { return os << t.buf; }
};

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    Text a(s1.c_str()), b(" "), c(s2.c_str());
    std::cout << (a + b + c) << "\n";
    return 0;
}
