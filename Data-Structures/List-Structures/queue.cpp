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
class Queue {
public:
    Queue(size_t _capacity = 1024) : head(0), tail(-1), size(0), capacity(_capacity), queue(new T[_capacity]) {}
    ~Queue() { delete[] queue; }
    size_t get_size() const {
        return size;
    }
    size_t get_capacity() const {
        return capacity;
    }
    bool empty() const {
        return (size == 0);
    }
    const T& front() const {
        if (empty()) throw queue_empty;
        return queue[head];
    }
    void push_back(const T& object) {
        if (size == capacity) throw queue_out_of_bound;
        ++size; ++tail;
        if (tail == capacity) tail = 0;
        queue[tail] = object;
    }
    T pop_front() {
        if (empty()) throw queue_empty;
        T popped = queue[head];
        --size; ++head;
        if (head == capacity) head = 0;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw queue_empty;
        for (int64_t i = head, s = size; s > 0; ++i, --s) {
            if (i == capacity) i = 0;
            out << queue[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* queue;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
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

    return 0;
}