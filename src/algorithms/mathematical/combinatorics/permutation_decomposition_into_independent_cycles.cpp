/*
    Permutation Decomposition Into Independent Cycles
    -------------------------------------------------
    Time: O(n log(n))
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>

auto PermutationDecompositionIntoIndependentCycles(std::vector<std::pair<unsigned, unsigned>>& permutation) {
    std::sort(permutation.begin(), permutation.end());
    unsigned position = 1, n = permutation.size();
    std::vector<bool> visited(n);
    std::vector<unsigned> cycle;
    std::vector<std::vector<unsigned>> cycles;
    while (position < n) {
        if (visited[position] == false) {
            visited[position] = true;
            cycle.emplace_back(position);
            position = permutation[position].second;
        } else {
            cycles.emplace_back(cycle);
            cycle.clear();
            position = n;
            for (unsigned i = 1; i < n; ++i) {
                if (visited[i] == false) {
                    position = i;
                    break;
                }
            }
        }
    }
    return cycles;
}

int main() {
    unsigned n;
    std::cin >> n;
    std::vector<std::pair<unsigned, unsigned>> permutation(++n);
    for (unsigned i = 1; i < n; ++i) {
        std::cin >> permutation[i].first;
    }
    for (unsigned i = 1; i < n; ++i) {
        std::cin >> permutation[i].second;
    }
    auto cycles = PermutationDecompositionIntoIndependentCycles(permutation);
    for (const auto& cycle : cycles) {
        for (const unsigned& position : cycle) {
            std::cout << position << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}