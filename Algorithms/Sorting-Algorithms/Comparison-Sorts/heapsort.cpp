/*
    Heapsort (unstable)
    ------------------------------------------
    Time: Ω(n log(n)) Θ(n log(n)) O(n log(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void SiftDown(std::vector<T> &heap, const size_t &i, const size_t &n)
{
    size_t i_max = i, left = 2 * i + 1, right = left + 1;
    if (left < n && heap[left] > heap[i_max])
        i_max = left;
    if (right < n && heap[right] > heap[i_max])
        i_max = right;
    if (i_max != i)
    {
        std::swap(heap[i], heap[i_max]);
        SiftDown(heap, i_max, n);
    }
}

template <typename T>
void Heapify(std::vector<T> &array)
{
    for (int i = array.size() / 2 - 1; i >= 0; --i)
    {
        SiftDown(array, i, array.size());
    }
}

template <typename T>
void Heapsort(std::vector<T> &array)
{
    Heapify(array);
    for (size_t i = array.size() - 1, n = array.size(); i > 0; --i)
    {
        std::swap(array[0], array[i]);
        SiftDown(array, 0, --n);
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Heapsort(array);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}