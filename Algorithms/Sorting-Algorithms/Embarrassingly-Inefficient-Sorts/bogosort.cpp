/*
    Bogosort (unstable)
    --------------------------
    Time: Ω(n) Θ((n+1)!) O(∞)
    Space: O(1)
*/
#include <iostream>
#include <vector>
#include <ctime>

template <typename T>
bool IsSorted(const std::vector<T> &array)
{
    bool isSorted = true;
    for (size_t n = array.size() - 1; n > 0; --n)
    {
        if (array[n] < array[n - 1])
        {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}

template <typename T>
void Bogosort(std::vector<T> &array)
{
    srand(time(0));
    while (IsSorted(array) == false)
    {
        for (size_t i = 0, n = array.size(); i < n; ++i)
        {
            std::swap(array[i], array[rand() % n]);
        }
    }
}

int main()
{
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Bogosort(array);
    for (const int &element : array)
    {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}