/*
    Nearest Neighbour Search
    -------------------------------------------------------------
    | Standard Binary Search | Leftmost-Rightmost Binary Search |
    -------------------------------------------------------------
    | Time: O(log(n))        |             O(log(n))            |
    | Space: O(1)            |               O(1)               |
    -------------------------------------------------------------
*/
#include <iostream>
#include <vector>

enum class Procedure {
    Standard = 0, LeftmostRightmost = 1
};

template <typename T>
unsigned NearestNeighbourSearch(const Procedure& procedure, const std::vector<T>& array, const T& key) {
    unsigned predecessor, successor, nearestNeighbour, mid, low = 0, high = array.size();
    switch (procedure) {
        case Procedure::LeftmostRightmost:
            // Leftmost binary search
            while (low < high) {
                mid = low + (high - low) / 2;
                (array[mid] < key) ? (low = mid + 1) : (high = mid);
            }
            predecessor = (low == 0) ? (low) : (low - 1);
            // Rightmost binary search
            while (low < high) {
                mid = low + (high - low) / 2;
                (array[mid] > key) ? (high = mid) : (low = mid + 1);
            }
            successor = (high < array.size()) ? (high) : (high - 1);
            nearestNeighbour = (array[successor] - key < key - array[predecessor]) ? (successor) : (predecessor);
            break;
        case Procedure::Standard:
            while (low < high) {
                mid = low + (high - low) / 2;
                if (array[mid] > key)
                    high = mid;
                else if (array[mid] < key)
                    low = mid + 1;
                else
                    return mid;
            }
            predecessor = low - 1, successor = low;
            nearestNeighbour = (successor == 0 || array[successor] - key < key - array[predecessor]) ? (successor) : (predecessor);
    }
    return nearestNeighbour;
}

int main() {
    int key;
    unsigned procedure, numElements;
    std::cin >> procedure >> numElements >> key;
    std::vector<int> array(numElements);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << NearestNeighbourSearch(static_cast<Procedure>(procedure), array, key) << std::endl;

    return EXIT_SUCCESS;
}