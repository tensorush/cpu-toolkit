/*
    Josephus Problem
    ----------------------------
    Time: O(hopSize*(numPeople))
    Space: O(1)
*/
#include <iostream>

int JosephusProblem(const size_t& n, const size_t& k) {
    if (n == 1) return 0;
    if (k == 1) return n - 1;
    if (k > n) return (JosephusProblem(n - 1, k) + k) % n;
    int safeIndex = JosephusProblem(n - n / k, k) - n % k;
    safeIndex += (safeIndex < 0)?(n):(safeIndex / (k - 1));
    return safeIndex;
}

int main() {
    size_t numPeople, hopSize;
    std::cin >> numPeople >> hopSize;
    std::cout << JosephusProblem(numPeople, hopSize) << std::endl;

    return 0;
}