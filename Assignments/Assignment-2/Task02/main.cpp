#include <iostream>
int& highestMark(int arr[], int n) {
    int idx = 0;
    for (int i = 1; i < n; ++i) if (arr[i] > arr[idx]) idx = i;
    return arr[idx];
}
int main() {
    int marks[4] = {72, 88, 91, 84};
    for (int i = 0; i < 4; ++i) std::cin >> marks[i];
    highestMark(marks, 4) += 2;
    std::cout << "Moderated highest mark: " << highestMark(marks, 4) << "\n";
    return 0;
}
