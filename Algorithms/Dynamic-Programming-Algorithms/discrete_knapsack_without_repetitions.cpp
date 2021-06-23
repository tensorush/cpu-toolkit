/*
    Discrete Knapsack Without Repetitions (0-1 Knapsack Problem)
    ------------------------------------------------------------
    Time: O(numItems*2^(log(knapsackCapacity)))
    Space: O(numItems*knapsackCapacity)
*/
#include <iostream>
#include <iomanip>
#include <vector>

struct Item
{
    unsigned weight, value;
};

unsigned DiscreteKnapsackWithoutRepetitions(const std::vector<Item> &items, const unsigned &knapsackCapacity)
{
    // TODO: Top-down (recursive) approach with hash table memoization + solution reconstruction
    std::vector<std::vector<unsigned>> totalValues(items.size() + 1, std::vector<unsigned>(knapsackCapacity + 1));
    for (size_t i = 1; i <= items.size(); ++i)
    {
        for (unsigned w = 1; w <= knapsackCapacity; ++w)
        {
            totalValues[i][w] = totalValues[i - 1][w];
            if (items[i - 1].weight <= w)
            {
                unsigned value = totalValues[i - 1][w - items[i - 1].weight] + items[i - 1].value;
                if (value > totalValues[i][w])
                    totalValues[i][w] = value;
            }
        }
    }
    return totalValues[items.size()][knapsackCapacity];
}

int main()
{
    unsigned numItems, knapsackCapacity;
    std::cin >> numItems >> knapsackCapacity;
    std::vector<Item> items(numItems);
    for (Item &item : items)
    {
        std::cin >> item.weight >> item.value;
    }
    std::cout << std::setprecision(3) << std::fixed
              << DiscreteKnapsackWithoutRepetitions(items, knapsackCapacity) << std::endl;

    return EXIT_SUCCESS;
}