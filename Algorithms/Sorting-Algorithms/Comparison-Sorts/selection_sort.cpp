/*
    Selection Sort (stable)
    ---------------------------
    Time: Ω(n^2) Θ(n^2) O(n^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void SelectionSort(std::vector<T> &array)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < array.size(); ++j)
        {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        std::swap(array[i], array[minIndex]);
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    SelectionSort(array);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}