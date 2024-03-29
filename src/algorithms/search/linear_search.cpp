/*
    Linear Search
    -------------
    Time: O(n)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
int LinearSearch(const std::vector<T>& array, const T& key) {
    unsigned n = array.size();
    for (unsigned i = 0; i < n; ++i) {
        if (array[i] == key)
            return i;
    }
    return -1;
}

int main() {
    unsigned n;
    int key;
    std::cin >> n >> key;
    std::vector<int> array(n);
    for (int& element : array) {
        std::cin >> element;
    }
    std::cout << LinearSearch(array, key) << std::endl;

    return EXIT_SUCCESS;
}