/*
    Circular Queue
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(1)  O(1) | No Support |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

constexpr size_t defaultCapacity = 10;
constexpr size_t defaultCapacityMultiplier = 2;

template <typename T>
class CircularQueue final {
public:
    explicit CircularQueue(const T& initialValue, const size_t& capacity = defaultCapacity) : _head(0), _tail(0), _size(1), _capacity(capacity), _queue(new T[capacity]) {
        _queue[_head] = initialValue;
    }
    CircularQueue(const CircularQueue& object) : _head(object._head), _tail(object._tail), _size(object._size), _capacity(object._capacity), _queue(new T[object._capacity]) {
        for (size_t i = 0; i < _size; ++i) {
            _queue[i] = object._queue[i];
        }
    }
    CircularQueue& operator=(const CircularQueue& object) {
        if (this != &object) {
            delete[] _queue;
            _head = object._head;
            _tail = object._tail;
            _size = object._size;
            _capacity = object._capacity;
            _queue = new T[object._capacity];
            for (size_t i = 0; i < _size; ++i) {
                _queue[i] = object._queue[i];
            }
        }
        return *this;
    }
    ~CircularQueue() {
        delete[] _queue;
    }
    size_t getSize() const {
        return _size;
    }
    size_t get_capacity() const {
        return _capacity;
    }
    bool empty() const {
        return (_size == 0);
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
    void pushBack(const T& element) {
        if (_size == _capacity)
            increaseCapacity();
        (_tail == _capacity - 1) ? (_tail = 0) : (++_tail);
        _queue[_tail] = element;
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
    T* _queue;
    size_t _head;
    size_t _tail;
    size_t _size;
    size_t _capacity;
    void increaseCapacity() {
        _capacity *= defaultCapacityMultiplier;
        T* _newQueue = new T[_capacity];
        for (size_t i = 0, j = _head; i < _size; ++i, (j == _size - 1) ? (j = 0) : (++j)) {
            _newQueue[i] = _queue[j];
        }
        delete[] _queue;
        _head = 0;
        _tail = _size - 1;
        _queue = _newQueue;
    }
    class CircularQueueEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Circular Queue is empty";
        }
    } circularQueueEmpty;
};

int main() {
    CircularQueue<int> queue_1(1);
    queue_1.pushBack(3);
    queue_1.pushBack(7);
    CircularQueue<int> queue_2 = queue_1;
    CircularQueue<int> queue_3(3, 30);
    queue_3 = queue_1;
    std::cout << queue_1.getSize() << ' '
        << queue_1.front() << ' '
        << queue_1.popFront() << ' '
        << queue_1.empty() << std::endl;
    queue_1.print();

    return EXIT_SUCCESS;
}