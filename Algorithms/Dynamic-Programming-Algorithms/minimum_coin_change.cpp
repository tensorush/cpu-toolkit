/*
    Minimum Coin Change
    ------------------------
    Time: O(change*numCoins)
    Space: O(change)
*/
#include <iostream>
#include <climits>
#include <vector>

std::size_t MinimumCoinChange(const size_t& change, const std::vector<size_t>& coins) {
    std::vector<size_t> minCoins(change + 1);
    for (size_t i = 1; i <= change; ++i) {
        minCoins[i] = UINT_MAX;
        for (size_t j = 0; j < coins.size(); ++j) {
            if (i >= coins[j]) {
                size_t numCoins = minCoins[i - coins[j]] + 1;
                if (numCoins < minCoins[i]) minCoins[i] = numCoins;
            }
        }
    }
    return minCoins[change];
}

int main() {
    size_t change, numCoins;
    std::cin >> change >> numCoins;
    std::vector<size_t> coins(numCoins);
    for (size_t i = 0; i < numCoins; ++i) {
        std::cin >> coins[i];
    }
    std::cout << MinimumCoinChange(change, coins) << std::endl;

    return 0;
}