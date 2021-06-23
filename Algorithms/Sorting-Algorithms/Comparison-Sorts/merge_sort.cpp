/*
    Merge Sort (stable)
    ------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n log(n))
    Space: O(n)
*/
#include <iostream>
#include <vector>

template <typename T>
void MergeSort(std::vector<T> &array, const size_t &low, const size_t &high)
{
    if (low == high)
        return;
    size_t mid = low + (high - low) / 2;
    MergeSort(array, low, mid);
    MergeSort(array, mid + 1, high);
    std::vector<T> merged(high - low + 1);
    size_t i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
        (array[i] <= array[j]) ? (merged[k++] = array[i++]) : (merged[k++] = array[j++]);
    while (i <= mid)
        merged[k++] = array[i++];
    while (j <= high)
        merged[k++] = array[j++];
    for (size_t i = 0; i < merged.size(); ++i)
    {
        array[low + i] = merged[i];
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    MergeSort(array, 0, array.size() - 1);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}