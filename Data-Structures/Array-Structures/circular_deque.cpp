/*
    Circular Deque
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
class CircularDeque final
{
public:
    explicit CircularDeque(const T &initialValue, const size_t &capacity = defaultCapacity) : _head(0), _tail(0), _size(1), _capacity(capacity), _deque(new T[capacity])
    {
        _deque[_head] = initialValue;
    }
    CircularDeque(const CircularDeque &object) : _head(object._head), _tail(object._tail), _size(object._size), _capacity(object._capacity), _deque(new T[object._capacity])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _deque[i] = object._deque[i];
        }
    }
    CircularDeque &operator=(const CircularDeque &object)
    {
        if (this != &object)
        {
            delete[] _deque;
            _head = object._head;
            _tail = object._tail;
            _size = object._size;
            _capacity = object._capacity;
            _deque = new T[object._capacity];
            for (size_t i = 0; i < _size; ++i)
            {
                _deque[i] = object._deque[i];
            }
        }
        return *this;
    }
    ~CircularDeque()
    {
        delete[] _deque;
    }
    size_t getSize() const
    {
        return _size;
    }
    size_t get_capacity() const
    {
        return _capacity;
    }
    bool empty() const
    {
        return (_size == 0);
    }
    T &front() const
    {
        if (empty())
            throw circularDequeEmpty;
        return _deque[_head];
    }
    T &back() const
    {
        if (empty())
            throw circularDequeEmpty;
        return _deque[_tail];
    }
    void pushFront(const T &element)
    {
        if (_size == _capacity)
            increaseCapacity();
        (_head == 0) ? (_head = _capacity - 1) : (--_head);
        _deque[_head] = element;
        ++_size;
    }
    T popFront()
    {
        if (empty())
            throw circularDequeEmpty;
        const T popped = _deque[_head];
        (_head == _capacity - 1) ? (_head = 0) : (++_head);
        --_size;
        return popped;
    }
    void pushBack(const T &element)
    {
        if (_size == _capacity)
            increaseCapacity();
        (_tail == _capacity - 1) ? (_tail = 0) : (++_tail);
        _deque[_tail] = element;
        ++_size;
    }
    T popBack()
    {
        if (empty())
            throw circularDequeEmpty;
        const T popped = _deque[_tail];
        (_tail == 0) ? (_tail = _capacity - 1) : (--_tail);
        --_size;
        return popped;
    }
    void print(std::ostream &out = std::cout) const
    {
        if (empty())
            throw circularDequeEmpty;
        for (size_t i = _head; i != _tail; (i == _capacity - 1) ? (i = 0) : (++i))
        {
            out << _deque[i] << ' ';
        }
        out << _deque[_tail] << std::endl;
    }

private:
    T *_deque;
    size_t _head;
    size_t _tail;
    size_t _size;
    size_t _capacity;
    void increaseCapacity()
    {
        _capacity *= defaultCapacityMultiplier;
        T *_newDeque = new T[_capacity];
        for (size_t i = 0, j = _head; i < _size; ++i, (j == _size - 1) ? (j = 0) : (++j))
        {
            _newDeque[i] = _deque[j];
        }
        delete[] _deque;
        _head = 0;
        _tail = _size - 1;
        _deque = _newDeque;
    }
    class CircularDequeEmptyException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Circular Deque is empty";
        }
    } circularDequeEmpty;
};

int main()
{
    CircularDeque<int> deque_1(1);
    deque_1.pushBack(3);
    deque_1.pushFront(7);
    CircularDeque<int> deque_2 = deque_1;
    CircularDeque<int> deque_3(3, 30);
    deque_3 = deque_1;
    std::cout << deque_1.getSize() << ' '
              << deque_1.front() << ' '
              << deque_1.popFront() << ' '
              << deque_1.empty() << std::endl;
    deque_1.print();

    return EXIT_SUCCESS;
}