/*
    Discrete Knapsack With Repetitions
    -------------------------------------------
    Time: O(numItems*2^(log(knapsackCapacity)))
    Space: O(knapsackCapacity)
*/
#include <iostream>
#include <vector>

struct Item {
    size_t weight, value;
};

size_t DiscreteKnapsackWithRepetitions(std::vector<Item>& items, const size_t& knapsackCapacity) {
    // TODO: Top-down (recursive) approach with hash table memoization + solution reconstruction
    std::vector<size_t> totalValues(knapsackCapacity + 1);
    for (size_t i = 0; i < items.size(); ++i) {
        for (size_t w = 1; w <= knapsackCapacity; ++w) {
            if (items[i].weight <= w) {
                size_t value = totalValues[w - items[i].weight] + items[i].value;
                if (value > totalValues[w]) totalValues[w] = value;
            }
        }
    }
    return totalValues[knapsackCapacity];
}

int main() {
    size_t numItems;
    size_t knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (size_t i = 0; i < numItems; ++i) {
        std::cin >> items[i].weight >> items[i].value;
    }
    std::cout.precision(3);
    std::cout << DiscreteKnapsackWithRepetitions(items, knapsackCapacity) << std::endl;

    return 0;
}