/*
    Dynamic Array
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(1)  O(1) | Θ(n)  O(n) |  Θ(n)  O(n) |  Θ(n)  O(n) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

constexpr size_t defaultCapacity = 10;
constexpr size_t defaultCapacityMultiplier = 2;

template <typename T>
class DynamicArray final {
public:
    explicit DynamicArray(const T& initialValue, const size_t& capacity = defaultCapacity) : _size(capacity), _capacity(capacity), _array(new T[capacity]) {
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = initialValue;
        }
    }
    DynamicArray(const DynamicArray& object) : _size(object._size), _capacity(object._capacity), _array(new T[object._capacity]) {
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = object._array[i];
        }
    }
    DynamicArray& operator=(const DynamicArray& object) {
        if (this != &object) {
            delete[] _array;
            _size = object._size;
            _capacity = object._capacity;
            _array = new T[object._capacity];
            for (size_t i = 0; i < _size; ++i) {
                _array[i] = object._array[i];
            }
        }
        return *this;
    }
    ~DynamicArray() {
        delete[] _array;
    }
    size_t getSize() const {
        return _size;
    }
    size_t getCapacity() const {
        return _capacity;
    }
    bool empty() const {
        return (_size == 0);
    }
    T& operator[](const int64_t& index) const {
        if (index < 0 || index >= _size)
            throw dynamicArrayOutOfBound;
        return _array[index];
    }
    int64_t find(const T& element) const {
        int64_t index = -1;
        for (size_t i = 0; i < _size; ++i) {
            if (_array[i] == element) {
                index = i;
                break;
            }
        }
        return index;
    }
    void insert(const T element, const int64_t& index) {
        if (index < 0 || index > _size)
            throw dynamicArrayOutOfBound;
        if (_size == _capacity)
            increaseCapacity();
        if (index < _size) {
            for (size_t i = _size; i > index; --i) {
                _array[i] = _array[i - 1];
            }
        }
        _array[index] = element;
        ++_size;
    }
    T remove(const int64_t& index) {
        if (index < 0 || index >= _size)
            throw dynamicArrayOutOfBound;
        const T deleted = _array[index];
        if (index < _size - 1) {
            for (size_t i = index; i < _size - 1; ++i) {
                _array[i] = _array[i + 1];
            }
        }
        --_size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw dynamicArrayEmpty;
        for (size_t i = 0; i < _size; ++i) {
            out << _array[i] << ' ';
        }
        out << std::endl;
    }

private:
    T* _array;
    size_t _size;
    size_t _capacity;
    void increaseCapacity() {
        _capacity *= defaultCapacityMultiplier;
        T* _newArray = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _newArray[i] = _array[i];
        }
        delete[] _array;
        _array = _newArray;
    }
    class DynamicArrayEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Dynamic array is empty";
        }
    } dynamicArrayEmpty;
    class DynamicArrayOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Dynamic array's index is out of bound";
        }
    } dynamicArrayOutOfBound;
};

int main() {
    DynamicArray<int> array_1(1);
    array_1[0] = 3;
    array_1.insert(7, 0);
    DynamicArray<int> array_2 = array_1;
    DynamicArray<int> array_3(3, 30);
    array_3 = array_1;
    std::cout << array_1.getSize() << ' '
        << array_1.find(7) << ' '
        << array_1[0] << ' '
        << array_1.remove(1) << ' '
        << array_1.getCapacity() << ' '
        << array_1.empty() << std::endl;
    array_1.print();

    return EXIT_SUCCESS;
}