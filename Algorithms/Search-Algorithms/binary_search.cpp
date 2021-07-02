/*
    Binary Search
    ----------------------------------------------------------------------------------
    | Basic Search    | Bottenbruch Alternative | Leftmost Search | Rightmost Search |
    ----------------------------------------------------------------------------------
    | Time: O(log(n)) |        O(log(n))        |    O(log(n))    |     O(log(n))    |
    | Space: O(1)     |           O(1)          |       O(1)      |        O(1)      |
    ----------------------------------------------------------------------------------

*/
#include <iostream>
#include <vector>

enum class Procedure {
    Basic = 0, Bottenbruch = 1, Leftmost = 2, Rightmost = 3
};

template <typename T>
unsigned BinarySearch(const Procedure& procedure, const std::vector<T>& array, const T& key) {
    unsigned found, mid, low = 0, high = array.size();
    switch (procedure) {
        case Procedure::Basic:
            while (low < high) {
                mid = low + (high - low) / 2;
                if (array[mid] < key)
                    low = mid + 1;
                else if (array[mid] > key)
                    high = mid;
                else
                    return mid;
            }
            found = low;
            break;
        case Procedure::Bottenbruch:
            while (low < high) {
                mid = (low + high + 1) / 2;
                (array[mid] > key) ? (high = mid - 1) : (low = mid);
            }
            found = low;
            break;
        case Procedure::Leftmost:
            while (low < high) {
                mid = low + (high - low) / 2;
                (array[mid] < key) ? (low = mid + 1) : (high = mid);
            }
            found = low;
            break;
        case Procedure::Rightmost:
            while (low < high) {
                mid = low + (high - low) / 2;
                (array[mid] > key) ? (high = mid) : (low = mid + 1);
            }
            found = high - 1;
    }
    return found;
}

int main() {
    int key;
    unsigned procedure, numElements;
    std::cin >> procedure >> numElements >> key;
    std::vector<int> array(numElements);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << BinarySearch(static_cast<Procedure>(procedure), array, key) << std::endl;

    return EXIT_SUCCESS;
}