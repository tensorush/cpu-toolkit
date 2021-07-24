/*
    Circular Queue
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
class CircularQueue final {
public:
    static constexpr size_t DEFAULT_CAPACITY = 10;
    static constexpr size_t DEFAULT_CAPACITY_MULTIPLIER = 2;
    explicit CircularQueue(const T& initialValue, const size_t& capacity = DEFAULT_CAPACITY) : _head(0), _tail(0), _size(1), _capacity(capacity), _queue(std::make_unique<T[]>(capacity)) {
        _queue[_head] = initialValue;
    }
    size_t getSize() const {
        return _size;
    }
    size_t getCapacity() const {
        return _capacity;
    }
    bool empty() const {
        return _size == 0;
    }
    T& front() const {
        if (empty())
            throw circularQueueEmpty;
        return _queue[_head];
    }
    T& back() const {
        if (empty())
            throw circularQueueEmpty;
        return _queue[_tail];
    }
    T popFront() {
        if (empty())
            throw circularQueueEmpty;
        const T popped = _queue[_head];
        (_head == _capacity - 1) ? (_head = 0) : (++_head);
        --_size;
        return popped;
    }
    void pushBack(const T& value) {
        if (_size == _capacity)
            _increaseCapacity();
        (_tail == _capacity - 1) ? (_tail = 0) : (++_tail);
        _queue[_tail] = value;
        ++_size;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw circularQueueEmpty;
        for (size_t i = _head; i != _tail; (i == _capacity - 1) ? (i = 0) : (++i)) {
            out << _queue[i] << ' ';
        }
        out << _queue[_tail] << std::endl;
    }
private:
    size_t _head;
    size_t _tail;
    size_t _size;
    size_t _capacity;
    std::unique_ptr<T[]> _queue;
    void _increaseCapacity() {
        _capacity *= DEFAULT_CAPACITY_MULTIPLIER;
        std::unique_ptr<T[]> _newQueue = std::make_unique<T[]>(_capacity);
        for (size_t i = 0, j = _head; i < _size; ++i, (j == _size - 1) ? (j = 0) : (++j)) {
            _newQueue[i] = _queue[j];
        }
        _head = 0;
        _tail = _size - 1;
        _queue = std::move(_newQueue);
    }
    class CircularQueueEmptyException : public std::exception {
        const char* what() const throw() {
            return "Circular Queue is empty";
        }
    } circularQueueEmpty;
};

int main() {
    CircularQueue<int> queue_1(1);
    queue_1.pushBack(3);
    queue_1.pushBack(7);
    std::cout << queue_1.getSize() << ' '
        << queue_1.front() << ' '
        << queue_1.popFront() << ' '
        << queue_1.empty() << std::endl;
    queue_1.print();

    return EXIT_SUCCESS;
}