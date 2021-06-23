/*
    Permutations With Repetitions
    -----------------------------
    Time: O(n^k)
    Space: O(1)
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

template <typename T>
auto _PermutationsWithRepetitions(const std::vector<T> &sequence, const std::vector<T> &permutation, std::vector<std::vector<T>> &permutations, const size_t &k)
{
    if (k == 0)
    {
        permutations.emplace_back(permutation);
        return;
    }
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::vector<T> newPermutation = permutation;
        newPermutation.emplace_back(sequence[i]);
        _PermutationsWithRepetitions(sequence, newPermutation, permutations, k - 1);
    }
}

template <typename T>
auto PermutationsWithRepetitions(std::vector<T> &sequence, const size_t &k)
{
    std::vector<T> permutation;
    std::vector<std::vector<T>> permutations;
    std::sort(sequence.begin(), sequence.end());
    _PermutationsWithRepetitions(sequence, permutation, permutations, k);
    return permutations;
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;
    std::vector<char> sequence(n);
    for (char &element : sequence)
    {
        std::cin >> element;
    }
    auto permutations = PermutationsWithRepetitions(sequence, k);
    for (const std::vector<char> &permutation : permutations)
    {
        for (const char &element : permutation)
        {
            std::cout << element;
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}