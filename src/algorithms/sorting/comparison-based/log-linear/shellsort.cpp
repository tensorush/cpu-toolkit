/*
    Shellsort (unstable)
    --------------------------------------------------
    Time: Ω(n log(n)) Θ(n (log(n))^2) O(n (log(n))^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template <typename T>
void Shellsort(std::vector<T>& array) {
    // Sedgewick-Incerpi gap sequence
    unsigned n = array.size();
    std::vector<unsigned> gaps = { 1391376, 463792, 198768, 86961, 33936, 13776,
                                   4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };
    for (const unsigned& gap : gaps) {
        for (unsigned i = gap; i < n; ++i) {
            unsigned j;
            T temp = array[i];
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    int element;
    std::vector<int> array;
    while (std::cin >> element)
        array.emplace_back(element);
    Shellsort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}