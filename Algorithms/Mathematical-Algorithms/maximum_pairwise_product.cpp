/*
    Maximum Pairwise Product
    ------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

long long MaximumPairwiseProduct(const std::vector<int>& numbers) {
    int max1, max2 = -1;
    for (size_t i = 0; i < numbers.size(); ++i) {
        int number = numbers[i];
        if (number > max1) {
            max2 = max1;
            max1 = number;
        } else if (number > max2) {
            max2 = number;
        }
    }
    return ((long long) max1) * max2;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaximumPairwiseProduct(numbers) << std::endl;

    return 0;
}