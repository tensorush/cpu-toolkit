/*
    Dynamic Stack
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
class DynamicStack final
{
public:
    explicit DynamicStack(const size_t &capacity = defaultCapacity) : _size(0), _capacity(capacity), _stack(new T[capacity]) {}
    DynamicStack(const DynamicStack &object) : _size(object._size), _capacity(object._capacity), _stack(new T[object._capacity])
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _stack[i] = object._stack[i];
        }
    }
    DynamicStack &operator=(const DynamicStack &object)
    {
        if (this != &object)
        {
            delete[] _stack;
            _size = object._size;
            _capacity = object._capacity;
            _stack = new T[object._capacity];
            for (size_t i = 0; i < _size; ++i)
            {
                _stack[i] = object._stack[i];
            }
        }
        return *this;
    }
    ~DynamicStack()
    {
        delete[] _stack;
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
    T &top() const
    {
        if (empty())
            throw dynamicStackEmpty;
        return _stack[_size - 1];
    }
    void push(const T &element)
    {
        if (_size == _capacity)
            increaseCapacity();
        _stack[_size] = element;
        ++_size;
    }
    T pop()
    {
        if (empty())
            throw dynamicStackEmpty;
        const T popped = _stack[_size - 1];
        --_size;
        return popped;
    }
    void print(std::ostream &out = std::cout) const
    {
        if (empty())
            throw dynamicStackEmpty;
        for (size_t i = 0; i < _size; ++i)
        {
            out << _stack[i] << ' ';
        }
        out << std::endl;
    }

private:
    T *_stack;
    size_t _size;
    size_t _capacity;
    void increaseCapacity()
    {
        _capacity *= defaultCapacityMultiplier;
        T *_newStack = new T[_capacity];
        for (size_t i = 0; i < _size; ++i)
        {
            _newStack[i] = _stack[i];
        }
        delete[] _stack;
        _stack = _newStack;
    }
    class StackEmptyException : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Dynamic Stack is empty";
        }
    } dynamicStackEmpty;
};

int main()
{
    DynamicStack<int> stack_1(1);
    stack_1.push(3);
    stack_1.push(7);
    DynamicStack<int> stack_2 = stack_1;
    DynamicStack<int> stack_3(30);
    stack_3 = stack_1;
    std::cout << stack_1.getSize() << ' '
              << stack_1.top() << ' '
              << stack_1.pop() << ' '
              << stack_1.empty() << std::endl;
    stack_1.print();

    return EXIT_SUCCESS;
}