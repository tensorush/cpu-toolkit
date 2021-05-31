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
class Array final {
public:
    Array(const size_t& capacity = 1024) : _size(0), _capacity(capacity), array(new T[capacity]) {}
    ~Array() { delete[] array; }
    size_t get_size() const {
        return _size;
    }
    size_t get_capacity() const {
        return _capacity;
    }
    bool empty() const {
        return (_size == 0);
    }
    T operator [] (const int64_t& index) const {
        if (index < 0 || index >= _size) throw array_out_of_bound;
        return array[index];
    }
    int64_t find(const T& object) const {
        for (int64_t i = 0; i < _size; ++i) {
            if (array[i] == object) return i;
        }
        return -1;
    }
    void insert(const T object, const int64_t& index) {
        if (index < 0 || index > _size) throw array_out_of_bound;
        if (_size == _capacity) {
            T* new_array = new T[2 * _capacity];
            for (size_t i = 0; i < _capacity; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            _capacity *= 2;
        }
        if (index < _size) {
            for (int64_t i = _size - 1; i >= index; --i) {
                array[i + 1] = array[i];
            }
        }
        array[index] = object;
        ++_size;
    }
    T remove(const int64_t& index) {
        if (index < 0 || index >= _size) throw array_out_of_bound;
        const T deleted = array[index];
        if (index < _size - 1) {
            for (size_t i = index; i <= _size - 2; ++i) {
                array[i] = array[i + 1];
            }
        }
        --_size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw array_empty;
        for (size_t i = 0; i < _size; ++i) {
            out << array[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* array;
    int64_t _size;
    int64_t _capacity;
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

    return EXIT_SUCCESS;
}