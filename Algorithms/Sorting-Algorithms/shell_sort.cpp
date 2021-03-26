/*
    Shell Sort (unstable)
    --------------------------------------------------
    Time: Ω(n log(n)) Θ(n (log(n))^2) O(n (log(n))^2)
    Space: O(1)
*/
#include <iostream>
#include <vector>

template<typename T>
void ShellSort(std::vector<T>& array) {
    // Sedgewick-Incerpi gap sequence
    std::vector<size_t> gaps = { 1391376, 463792, 198768, 86961, 33936, 13776,
                                 4592, 1968, 861, 336, 112, 48, 21, 7, 3, 1 };
    for (size_t gap : gaps) {
        for (size_t i = gap; i < array.size(); ++i) {
            T temp = array[i];
            size_t j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<int> array(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    ShellSort(array);
    for (const int& element : array) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;

    return 0;
}