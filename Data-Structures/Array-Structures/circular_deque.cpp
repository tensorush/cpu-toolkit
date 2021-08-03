/*
    Circular Deque
    --------------------------------------------------------
    |   Operations Only Allowed at the Beginning and End   |
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
class CircularDeque final {
public:
    static constexpr unsigned DEFAULT_CAPACITY = 10;
    static constexpr unsigned DEFAULT_CAPACITY_MULTIPLIER = 2;
    explicit CircularDeque(const T& initialValue, const unsigned& capacity = DEFAULT_CAPACITY) : _head(0), _tail(0), _size(1), _capacity(capacity), _deque(std::make_unique<T[]>(capacity)) {
        _deque[_head] = initialValue;
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
    T& front() const {
        if (empty())
            throw circularDequeEmpty;
        return _deque[_head];
    }
    T& back() const {
        if (empty())
            throw circularDequeEmpty;
        return _deque[_tail];
    }
    void pushFront(const T& value) {
        if (_size == _capacity)
            _increaseCapacity();
        (_head == 0) ? (_head = _capacity - 1) : (--_head);
        _deque[_head] = value;
        ++_size;
    }
    T popFront() {
        if (empty())
            throw circularDequeEmpty;
        const T popped = _deque[_head];
        (_head == _capacity - 1) ? (_head = 0) : (++_head);
        --_size;
        return popped;
    }
    void pushBack(const T& value) {
        if (_size == _capacity)
            _increaseCapacity();
        (_tail == _capacity - 1) ? (_tail = 0) : (++_tail);
        _deque[_tail] = value;
        ++_size;
    }
    T popBack() {
        if (empty())
            throw circularDequeEmpty;
        const T popped = _deque[_tail];
        (_tail == 0) ? (_tail = _capacity - 1) : (--_tail);
        --_size;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw circularDequeEmpty;
        for (unsigned i = _head; i != _tail; (i == _capacity - 1) ? (i = 0) : (++i)) {
            out << _deque[i] << ' ';
        }
        out << _deque[_tail] << std::endl;
    }
private:
    unsigned _head;
    unsigned _tail;
    unsigned _size;
    unsigned _capacity;
    std::unique_ptr<T[]> _deque;
    void _increaseCapacity() {
        _capacity *= DEFAULT_CAPACITY_MULTIPLIER;
        std::unique_ptr<T[]> _newDeque = std::make_unique<T[]>(_capacity);
        for (unsigned i = 0, j = _head; i < _size; ++i, (j == _size - 1) ? (j = 0) : (++j)) {
            _newDeque[i] = _deque[j];
        }
        _head = 0;
        _tail = _size - 1;
        _deque = std::move(_newDeque);
    }
    class CircularDequeEmptyException : public std::exception {
        const char* what() const throw() {
            return "Circular Deque is empty";
        }
    } circularDequeEmpty;
};

int main() {
    CircularDeque<int> deque_1(1);
    deque_1.pushBack(3);
    deque_1.pushFront(7);
    std::cout << deque_1.getSize() << ' '
        << deque_1.front() << ' '
        << deque_1.popFront() << ' '
        << deque_1.empty() << std::endl;
    deque_1.print();

    return EXIT_SUCCESS;
}