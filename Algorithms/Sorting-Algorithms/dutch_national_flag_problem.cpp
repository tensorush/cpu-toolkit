/*
    Dutch National Flag Problem (stable)
    ------------------------------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void DutchNationalFlagProblem(std::vector<T>& array, size_t& mid) {
    int low = 0, equal = 0, high = array.size() - 1;
    while (equal <= high) {
        if (array[equal] < mid) {
            std::swap(array[low++], array[equal++]);
        } else if (array[equal] > mid) {
            std::swap(array[equal], array[high--]);
        } else {
            ++equal;
        }
    }
}

int main() {
    size_t n, mid;
    std::cin >> n >> mid;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    DutchNationalFlagProblem(array, mid);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}