/*
    Maximum Pairwise Product
    ------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <tuple>

auto MaximumPairwiseProduct(const std::vector<int>& numbers) {
    long long min_1 = INT32_MAX, min_2 = INT32_MAX,
        max_1 = INT32_MIN, max_2 = INT32_MIN;
    for (const int& number : numbers) {
        if (number < min_1) {
            min_2 = min_1;
            min_1 = number;
        } else if (number < min_2) {
            min_2 = number;
        }
        if (number > max_1) {
            max_2 = max_1;
            max_1 = number;
        } else if (number > max_2) {
            max_2 = number;
        }
    }
    int smaller, larger;
    long long product, min = min_1 * min_2, max = max_1 * max_2;
    if (min > max) {
        smaller = min_1;
        larger = min_2;
        product = min;
    } else {
        smaller = max_2;
        larger = max_1;
        product = max;
    }
    return std::make_tuple(smaller, larger, product);
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int& number : numbers) {
        std::cin >> number;
    }
    auto [smaller, larger, product] = MaximumPairwiseProduct(numbers);
    std::cout << smaller << " * " << larger << " = " << product << std::endl;

    return EXIT_SUCCESS;
}