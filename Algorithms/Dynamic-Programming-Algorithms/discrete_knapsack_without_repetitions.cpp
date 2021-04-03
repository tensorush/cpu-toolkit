/*
    Discrete Knapsack Without Repetitions (0-1 Knapsack Problem)
    ------------------------------------------------------------
    Time: O(numItems*2^(log(knapsackCapacity)))
    Space: O(numItems*knapsackCapacity)
*/
#include <iostream>
#include <vector>

struct Item {
    size_t weight, value;
};

size_t DiscreteKnapsackWithoutRepetitions(std::vector<Item>& items, const size_t& knapsackCapacity) {
    // TODO: Top-down (recursive) approach with hash table memoization + solution reconstruction
    std::vector<std::vector<size_t>> totalValues(items.size() + 1, std::vector<size_t>(knapsackCapacity + 1));
    for (size_t i = 1; i <= items.size(); ++i) {
        for (size_t w = 1; w <= knapsackCapacity; ++w) {
            totalValues[i][w] = totalValues[i - 1][w];
            if (items[i - 1].weight <= w) {
                size_t value = totalValues[i - 1][w - items[i - 1].weight] + items[i - 1].value;
                if (value > totalValues[i][w]) totalValues[i][w] = value;
            }
        }
    }
    return totalValues[items.size()][knapsackCapacity];
}

int main() {
    size_t numItems, knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (size_t i = 0; i < numItems; ++i) {
        std::cin >> items[i].weight >> items[i].value;
    }
    std::cout.precision(3);
    std::cout << DiscreteKnapsackWithoutRepetitions(items, knapsackCapacity) << std::endl;

    return 0;
}