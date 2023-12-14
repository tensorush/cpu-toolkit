/*
    Dynamic Array
    --------------------------------------------------------
    |      Operations Allowed at Arbitrary Positions       |
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(1)  O(1) | Θ(n)  O(n) |  Θ(n)  O(n) |  Θ(n)  O(n) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>
#include <memory>

template <typename T>
class DynamicArray final {
public:
    static constexpr unsigned DEFAULT_CAPACITY = 10;
    static constexpr unsigned DEFAULT_CAPACITY_MULTIPLIER = 2;
    explicit DynamicArray(const T& initialValue, const unsigned& capacity = DEFAULT_CAPACITY) : _size(capacity), _capacity(capacity), _array(std::make_unique<T[]>(capacity)) {
        for (unsigned i = 0; i < _size; ++i) {
            _array[i] = initialValue;
        }
    }
    unsigned getSize() const {
        return _size;
    }
    unsigned getCapacity() const {
        return _capacity;
    }
    bool empty() const {
        return _size == 0;
    }
    T& operator [] (const int64_t& index) const {
        if (index < 0 || index >= _size)
            throw dynamicArrayOutOfBound;
        return _array[index];
    }
    int64_t find(const T& value) const {
        int64_t index = -1;
        for (unsigned i = 0; i < _size; ++i) {
            if (_array[i] == value) {
                index = i;
                break;
            }
        }
        return index;
    }
    void insert(const T& value, const int64_t& index) {
        if (index < 0 || index > _size)
            throw dynamicArrayOutOfBound;
        if (_size == _capacity)
            _increaseCapacity();
        if (index < _size) {
            for (unsigned i = _size; i > index; --i) {
                _array[i] = _array[i - 1];
            }
        }
        _array[index] = value;
        ++_size;
    }
    T remove(const int64_t& index) {
        if (index < 0 || index >= _size)
            throw dynamicArrayOutOfBound;
        const T deleted = _array[index];
        if (index < _size - 1) {
            for (unsigned i = index; i < _size - 1; ++i) {
                _array[i] = _array[i + 1];
            }
        }
        --_size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw dynamicArrayEmpty;
        for (unsigned i = 0; i < _size; ++i) {
            out << _array[i] << ' ';
        }
        out << std::endl;
    }
private:
    unsigned _size;
    unsigned _capacity;
    std::unique_ptr<T[]> _array;
    void _increaseCapacity() {
        _capacity *= DEFAULT_CAPACITY_MULTIPLIER;
        std::unique_ptr<T[]> _newArray = std::make_unique<T[]>(_capacity);
        for (unsigned i = 0; i < _size; ++i) {
            _newArray[i] = _array[i];
        }
        _array = std::move(_newArray);
    }
    class DynamicArrayEmptyException : public std::exception {
        const char* what() const throw() {
            return "Dynamic array is empty";
        }
    } dynamicArrayEmpty;
    class DynamicArrayOutOfBoundException : public std::exception {
        const char* what() const throw() {
            return "Dynamic array's index is out of bound";
        }
    } dynamicArrayOutOfBound;
};

int main() {
    DynamicArray<int> array_1(1);
    array_1[0] = 3;
    array_1.insert(7, 0);
    std::cout << array_1.getSize() << ' '
        << array_1.find(7) << ' '
        << array_1[0] << ' '
        << array_1.remove(1) << ' '
        << array_1.getCapacity() << ' '
        << array_1.empty() << std::endl;
    array_1.print();

    return EXIT_SUCCESS;
}