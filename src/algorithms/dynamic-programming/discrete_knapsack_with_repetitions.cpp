/*
    Discrete Knapsack With Repetitions (Unbounded Knapsack Problem)
    ---------------------------------------------------------------
    Time: O(numItems*2^(log(knapsackCapacity)))
    Space: O(knapsackCapacity)
*/
#include <iostream>
#include <iomanip>
#include <vector>

struct Item {
    unsigned weight, value;
};

unsigned DiscreteKnapsackWithRepetitions(const std::vector<Item>& items, const unsigned& knapsackCapacity) {
    std::vector<unsigned> totalValues(knapsackCapacity + 1);
    for (size_t i = 0; i < items.size(); ++i) {
        for (unsigned w = 1; w <= knapsackCapacity; ++w) {
            if (items[i].weight <= w) {
                unsigned value = totalValues[w - items[i].weight] + items[i].value;
                if (value > totalValues[w])
                    totalValues[w] = value;
            }
        }
    }
    return totalValues[knapsackCapacity];
}

int main() {
    unsigned numItems, knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (Item& item : items) {
        std::cin >> item.weight >> item.value;
    }
    std::cout << std::setprecision(3) << std::fixed << DiscreteKnapsackWithRepetitions(items, knapsackCapacity) << std::endl;

    return EXIT_SUCCESS;
}
