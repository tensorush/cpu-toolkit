/*
    Array
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(1)  O(1) | Θ(n)  O(n) |  Θ(n)  O(n) |  Θ(n)  O(n) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Array {
public:
    Array(size_t _capacity = 1024) : size(0), capacity(_capacity), array(new T[_capacity]) {}
    ~Array() { delete[] array; }
    size_t get_size() const {
        return size;
    }
    size_t get_capacity() const {
        return capacity;
    }
    bool empty() const {
        return (size == 0);
    }
    T operator [] (const int64_t& index) const {
        if (index < 0 || index >= size) throw array_out_of_bound;
        return array[index];
    }
    int64_t find(const T& object) const {
        for (int64_t i = 0; i < size; ++i) {
            if (array[i] == object) return i;
        }
        return -1;
    }
    void insert(const T object, const int64_t& index) {
        if (index < 0 || index > size) throw array_out_of_bound;
        if (size == capacity) {
            T* new_array = new T[2 * capacity];
            for (size_t i = 0; i < capacity; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity *= 2;
        }
        if (index < size) {
            for (int64_t i = size - 1; i >= index; --i) {
                array[i + 1] = array[i];
            }
        }
        array[index] = object;
        ++size;
    }
    T remove(const int64_t& index) {
        if (index < 0 || index >= size) throw array_out_of_bound;
        const T deleted = array[index];
        if (index < size - 1) {
            for (size_t i = index; i <= size - 2; ++i) {
                array[i] = array[i + 1];
            }
        }
        --size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw array_empty;
        for (size_t i = 0; i < size; ++i) {
            out << array[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* array;
    int64_t size;
    int64_t capacity;
    class ArrayEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Array is empty";
        }
    } array_empty;
    class ArrayOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Array index out of bound";
        }
    } array_out_of_bound;
};

int main() {
    Array<int> array(1);
    array.insert(3, 0);
    array.insert(7, 0);
    std::cout << array.get_size() << ' '
              << array.find(7) << ' '
              << array[0] << ' '
              << array.remove(1) << ' '
              << array.get_capacity() << ' '
              << array.empty() << std::endl;
    array.print();

    return 0;
}