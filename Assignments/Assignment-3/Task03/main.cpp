#include <iostream>
class Auditorium {
    int rows, cols;
    char** seats;
public:
    Auditorium(int r, int c) : rows(r), cols(c), seats(r > 0 ? new char*[r] : nullptr) {
        for (int i = 0; i < rows; ++i) {
            seats[i] = new char[cols];
            for (int j = 0; j < cols; ++j) seats[i][j] = 'O';
        }
    }
    ~Auditorium() {
        for (int i = 0; i < rows; ++i) delete[] seats[i];
        delete[] seats;
        std::cout << "Auditorium (" << rows << "x" << cols << ") destroyed cleanly.\n";
    }
};
int main() {
    int r, c;
    std::cin >> r >> c;
    Auditorium hall(r, c);
    return 0;
}
