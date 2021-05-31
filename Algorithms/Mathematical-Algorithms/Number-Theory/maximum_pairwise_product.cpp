/*
    Maximum Pairwise Product
    ------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

long long MaximumPairwiseProduct(const std::vector<int>& numbers) {
    long long max = INT32_MIN, max_2 = INT32_MIN;
    long long min = INT32_MAX, min_2 = INT32_MAX;
    for (const int& number : numbers) {
        if (number > max) {
            max_2 = max;
            max = number;
        } else if (number > max_2) {
            max_2 = number;
        } else if (number < min) {
            min_2 = min;
            min = number;
        } else if (number < min_2) {
            min_2 = number;
        }
    }
    max *= max_2;
    min *= min_2;
    return (max > min)?(max):(min);
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int& number : numbers) {
        std::cin >> number;
    }
    std::cout << MaximumPairwiseProduct(numbers) << std::endl;

    return EXIT_SUCCESS;
}