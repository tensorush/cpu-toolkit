/*
    Minimum Coin Change
    ------------------------
    Time: O(change*numCoins)
    Space: O(change)
*/
#include <iostream>
#include <vector>

unsigned MinimumCoinChange(const unsigned& change, const std::vector<unsigned>& coins) {
    std::vector<unsigned> minCoins(change + 1);
    for (unsigned i = 1; i <= change; ++i) {
        minCoins[i] = UINT32_MAX;
        for (size_t j = 0; j < coins.size(); ++j) {
            if (i >= coins[j]) {
                unsigned numCoins = minCoins[i - coins[j]] + 1;
                if (numCoins < minCoins[i]) minCoins[i] = numCoins;
            }
        }
    }
    return minCoins[change];
}

int main() {
    unsigned change, numCoins;
    std::cin >> change >> numCoins;
    std::vector<unsigned> coins(numCoins);
    for (unsigned& coin : coins) {
        std::cin >> coin;
    }
    std::cout << MinimumCoinChange(change, coins) << std::endl;

    return 0;
}