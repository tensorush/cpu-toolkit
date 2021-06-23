/*
    Stooge Sort (stable)
    ------------------------------------
    Time: Ω(n^2.71) Θ(n^2.71) O(n^2.71)
    Space: O(n)
*/
#include <iostream>
#include <vector>

template <typename T>
void StoogeSort(std::vector<T> &array, const size_t &low, const size_t &high)
{
    if (array[low] > array[high])
        std::swap(array[low], array[high]);
    if (high - low + 1 > 2)
    {
        size_t third = (high - low + 1) / 3;
        StoogeSort(array, low, high - third);
        StoogeSort(array, low + third, high);
        StoogeSort(array, low, high - third);
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    StoogeSort(array, 0, array.size() - 1);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}