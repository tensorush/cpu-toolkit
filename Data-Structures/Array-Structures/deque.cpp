/*
    Deque
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  Θ(1) |  Θ(1)  Θ(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Deque {
public:
    Deque(size_t _capacity = 1024) : head(0), tail(-1), size(0), capacity(_capacity), deque(new T[_capacity]) {}
    ~Deque() { delete[] deque; }
    size_t get_size() const {
        return size;
    }
    size_t getcapacity() const {
        return capacity;
    }
    bool empty() const {
        return (size == 0);
    }
    const T& front() const {
        if (empty()) throw deque_empty;
        return deque[head];
    }
    const T& back() const {
        if (empty()) throw deque_empty;
        return deque[tail];
    }
    void push_front(const T& object) {
        if (size == capacity) throw deque_out_of_bound;
        (head == 0)?(head = capacity - 1):(--head);
        ++size;
        deque[head] = object;
    }
    T pop_front() {
        if (empty()) throw deque_empty;
        T popped = deque[head];
        --size; ++head;
        if (head == capacity) head = 0;
        return popped;
    }
    void push_back(const T& object) {
        if (size == capacity) throw deque_out_of_bound;
        ++size; ++tail;
        if (tail == capacity) tail = 0;
        deque[tail] = object;
    }
    T pop_back() {
        if (empty()) throw deque_empty;
        T popped = deque[tail];
        (tail == 0)?(tail = capacity - 1):(--tail);
        --size;
        return popped;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw deque_empty;
        for (int64_t i = head, s = size; s > 0; ++i, --s) {
            if (i == capacity) i = 0;
            out << deque[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* deque;
    size_t head;
    size_t tail;
    size_t size;
    size_t capacity;
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

    return 0;
}