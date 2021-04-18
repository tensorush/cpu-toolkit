/*
    Sorted Fractional Knapsack
    --------------------------
    Time: O(numItems)
    Space: O(1)
*/
#include <iostream>
#include <vector>

struct Item {
    double weight, value;
};

auto SortedFractionalKnapsack(std::vector<Item>& items, double& knapsackCapacity) {
    double totalValue = 0;
    std::vector<Item> knapsack(items.size());
    for (size_t i = 0; i < items.size(); ++i) {
        if (knapsackCapacity == 0) break ;
        knapsack[i].weight = (items[i].weight < knapsackCapacity)?(items[i].weight):(knapsackCapacity);
        knapsack[i].value = knapsack[i].weight * items[i].value / items[i].weight;
        knapsackCapacity -= knapsack[i].weight;
        items[i].weight -= knapsack[i].weight;
        totalValue += knapsack[i].value;
    }
    return std::make_pair(totalValue, knapsack);
}

int main() {
    size_t numItems;
    double knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (size_t i = 0; i < numItems; ++i) {
        std::cin >> items[i].weight >> items[i].value;
    }
    std::cout.precision(3);
    std::cout << SortedFractionalKnapsack(items, knapsackCapacity).first << std::endl;

    return 0;
}