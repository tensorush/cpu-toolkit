/*
    Binary Search
    ---------------
    Time: O(log(n))
    Space: O(1)
*/
#include <iostream>
#include <vector>

enum class Procedure
{
    Leftmost = 0,
    Rightmost = 1
};

template <typename T>
unsigned BinarySearch(const Procedure &procedure, const std::vector<T> &array, const T &key)
{
    unsigned mid, found, low = 0, high = array.size();
    switch (procedure)
    {
    case Procedure::Leftmost:
        while (low < high)
        {
            mid = (low + high) / 2;
            (array[mid] < key) ? (low = mid + 1) : (high = mid);
        }
        found = low;
        break;
    case Procedure::Rightmost:
        while (low < high)
        {
            mid = (low + high) / 2;
            (array[mid] > key) ? (high = mid) : (low = mid + 1);
        }
        found = high - 1;
    }
    return found;
}

int main()
{
    int key;
    unsigned procedure, numElements;
    std::cin >> procedure >> numElements >> key;
    std::vector<int> array(numElements);
    for (int &element : array)
    {
        std::cin >> element;
    }
    std::cout << BinarySearch(static_cast<Procedure>(procedure), array, key) << std::endl;

    return EXIT_SUCCESS;
}