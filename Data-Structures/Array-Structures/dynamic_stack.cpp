/*
    Dynamic Stack
    --------------------------------------------------------
    |       Operations Only Allowed at the Beginning       |
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(1)  O(1) | No Support |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>
#include <memory>

template <typename T>
class DynamicStack final {
public:
    static constexpr size_t DEFAULT_CAPACITY = 10;
    static constexpr size_t DEFAULT_CAPACITY_MULTIPLIER = 2;
    explicit DynamicStack(const size_t& capacity = DEFAULT_CAPACITY) : _size(0), _capacity(capacity), _stack(std::make_unique<T[]>(capacity)) {}
    size_t getSize() const {
        return _size;
    }
    size_t getCapacity() const {
        return _capacity;
    }
    bool empty() const {
        return _size == 0;
    }
    T& top() const {
        if (empty())
            throw dynamicStackEmpty;
        return _stack[_size - 1];
    }
    void push(const T& value) {
        if (_size == _capacity)
            _increaseCapacity();
        _stack[_size] = value;
        ++_size;
    }
    T pop() {
        if (empty())
            throw dynamicStackEmpty;
        const T popped = _stack[_size - 1];
        --_size;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw dynamicStackEmpty;
        for (size_t i = 0; i < _size; ++i) {
            out << _stack[i] << ' ';
        }
        out << std::endl;
    }
private:
    size_t _size;
    size_t _capacity;
    std::unique_ptr<T[]> _stack;
    void _increaseCapacity() {
        _capacity *= DEFAULT_CAPACITY_MULTIPLIER;
        std::unique_ptr<T[]> _newStack = std::make_unique<T[]>(_capacity);
        for (size_t i = 0; i < _size; ++i) {
            _newStack[i] = _stack[i];
        }
        _stack = std::move(_newStack);
    }
    class StackEmptyException : public std::exception {
        const char* what() const throw() {
            return "Dynamic Stack is empty";
        }
    } dynamicStackEmpty;
};

int main() {
    DynamicStack<int> stack_1(1);
    stack_1.push(3);
    stack_1.push(7);
    std::cout << stack_1.getSize() << ' '
        << stack_1.top() << ' '
        << stack_1.pop() << ' '
        << stack_1.empty() << std::endl;
    stack_1.print();

    return EXIT_SUCCESS;
}