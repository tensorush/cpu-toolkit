/*
    Queue
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Queue final {
public:
    Queue(const size_t& capacity = 1024) : head(0), tail(-1), _size(0), _capacity(capacity), queue(new T[capacity]) {}
    ~Queue() { delete[] queue; }
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
        if (empty()) throw queue_empty;
        return queue[head];
    }
    void push_back(const T& object) {
        if (_size == _capacity) throw queue_out_of_bound;
        ++_size; ++tail;
        if (tail == _capacity) tail = 0;
        queue[tail] = object;
    }
    T pop_front() {
        if (empty()) throw queue_empty;
        T popped = queue[head];
        --_size; ++head;
        if (head == _capacity) head = 0;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw queue_empty;
        for (int64_t i = head, s = _size; s > 0; ++i, --s) {
            if (i == _capacity) i = 0;
            out << queue[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* queue;
    size_t head;
    size_t tail;
    size_t _size;
    size_t _capacity;
    class QueueEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Queue is empty";
        }
    } queue_empty;
    class QueueOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Queue index out of bound";
        }
    } queue_out_of_bound;
};

int main() {
    Queue<int> queue(10);
    queue.push_back(3);
    queue.push_back(7);
    std::cout << queue.get_size() << ' '
              << queue.front() << ' '
              << queue.pop_front() << ' '
              << queue.empty() << std::endl;
    queue.print();

    return EXIT_SUCCESS;
}