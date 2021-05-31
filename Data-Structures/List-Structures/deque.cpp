/*
    Deque
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Deque final {
public:
    Deque(const size_t& capacity = 1024) : _head(0), _tail(-1), _size(0), _capacity(capacity), deque(new T[capacity]) {}
    ~Deque() { delete[] deque; }
    size_t get_size() const {
        return _size;
    }
    size_t get_capacity() const {
        return _capacity;
    }
    bool empty() const {
        return (_size == 0);
    }
    const T& front() const {
        if (empty()) throw deque_empty;
        return deque[_head];
    }
    const T& back() const {
        if (empty()) throw deque_empty;
        return deque[_tail];
    }
    void push_front(const T& object) {
        if (_size == _capacity) throw deque_out_of_bound;
        (_head == 0)?(_head = _capacity - 1):(--_head);
        ++_size;
        deque[_head] = object;
    }
    T pop_front() {
        if (empty()) throw deque_empty;
        T popped = deque[_head];
        --_size; ++_head;
        if (_head == _capacity) _head = 0;
        return popped;
    }
    void push_back(const T& object) {
        if (_size == _capacity) throw deque_out_of_bound;
        ++_size; ++_tail;
        if (_tail == _capacity) _tail = 0;
        deque[_tail] = object;
    }
    T pop_back() {
        if (empty()) throw deque_empty;
        T popped = deque[_tail];
        (_tail == 0)?(_tail = _capacity - 1):(--_tail);
        --_size;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw deque_empty;
        for (int64_t i = _head, s = _size; s > 0; ++i, --s) {
            if (i == _capacity) i = 0;
            out << deque[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* deque;
    size_t _head;
    size_t _tail;
    size_t _size;
    size_t _capacity;
    class DequeEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Deque is empty";
        }
    } deque_empty;
    class DequeOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Deque index out of bound";
        }
    } deque_out_of_bound;
};

int main() {
    Deque<int> deque(10);
    deque.push_back(3);
    deque.push_front(7);
    std::cout << deque.get_size() << ' '
              << deque.front() << ' '
              << deque.pop_front() << ' '
              << deque.empty() << std::endl;
    deque.print();

    return EXIT_SUCCESS;
}