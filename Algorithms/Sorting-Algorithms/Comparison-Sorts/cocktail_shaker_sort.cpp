/*
    Cocktail Shaker Sort (stable)
    -----------------------------
    Time: Ω(n) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void CocktailShakerSort(std::vector<T> &array)
{
    size_t low = 0, high = array.size() - 1, swapped = low;
    while (low < high)
    {
        for (size_t i = high; i > low; --i)
        {
            if (array[i - 1] > array[i])
            {
                std::swap(array[i - 1], array[i]);
                swapped = i;
            }
        }
        low = swapped;
        for (size_t i = low; i < high; ++i)
        {
            if (array[i] > array[i + 1])
            {
                std::swap(array[i], array[i + 1]);
                swapped = i;
            }
        }
        high = swapped;
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    CocktailShakerSort(array);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}