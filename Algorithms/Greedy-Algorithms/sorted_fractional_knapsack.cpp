/*
    Sorted Fractional Knapsack
    --------------------------
    Time: O(numItems)
    Space: O(1)
*/
#include <iostream>
#include <iomanip>
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
    unsigned numItems;
    double knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (Item& item : items) {
        std::cin >> item.weight >> item.value;
    }
    auto [totalValue, knapsack] = SortedFractionalKnapsack(items, knapsackCapacity);
    std::cout << std::setprecision(3) << std::fixed
              << totalValue << std::endl;

    return EXIT_SUCCESS;
}