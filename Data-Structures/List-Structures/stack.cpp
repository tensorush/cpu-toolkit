/*
    Stack
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Stack final {
public:
    Stack(const size_t& capacity = 1024) : _size(0), _capacity(capacity), stack(new T[capacity]) {}
    ~Stack() { delete[] stack; }
    size_t get_size() const {
        return _size;
    }
    size_t get_capacity() const {
        return _capacity;
    }
    bool empty() const {
        return (_size == 0);
    }
    const T& top() const {
        if (empty()) throw stack_empty;
        return stack[_size - 1];
    }
    void push_back(const T& object) {
        if (_size == _capacity) throw stack_out_of_bound;
        stack[_size++] = object;
    }
    T pop_back() {
        if (empty()) throw stack_empty;
        return stack[--_size];
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw stack_empty;
        for (int64_t i = _size - 1; i >= 0; --i) {
            out << stack[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* stack;
    size_t _size;
    size_t _capacity;
    class EmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Stack is empty";
        }
    } stack_empty;
    class OutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Stack index out of bound";
        }
    } stack_out_of_bound;
};

int main() {
    Stack<int> stack(10);
    stack.push_back(3);
    stack.push_back(7);
    std::cout << stack.get_size() << ' '
              << stack.top() << ' '
              << stack.pop_back() << ' '
              << stack.empty() << std::endl;
    stack.print();

    return EXIT_SUCCESS;
}