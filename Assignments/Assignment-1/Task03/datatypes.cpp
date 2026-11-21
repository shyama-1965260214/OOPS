#include <iostream>
#include <climits>

int main() {
    long long journeys = 3000000LL;
    std::cin >> journeys;
    long long dailyCollection = journeys * 3600LL;
    std::cout << "sizeof(int): " << sizeof(int) << ", sizeof(long long): " << sizeof(long long) << "\n";
    std::cout << "Network Daily Collection (paise): " << dailyCollection << "\n";
    return 0;
}
