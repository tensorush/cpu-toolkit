/*
    Stack
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  Θ(1) |  Θ(1)  Θ(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class Stack {
public:
    Stack(size_t _capacity = 1024) : size(0), capacity(_capacity), stack(new T[_capacity]) {}
    ~Stack() { delete[] stack; }
    size_t get_size() const {
        return size;
    }
    size_t get_capacity() const {
        return capacity;
    }
    bool empty() const {
        return (size == 0);
    }
    const T& top() const {
        if (empty()) throw stack_empty;
        return stack[size - 1];
    }
    void push_back(const T& object) {
        if (size == capacity) throw stack_out_of_bound;
        stack[size++] = object;
    }
    T pop_back() {
        if (empty()) throw stack_empty;
        return stack[--size];
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw stack_empty;
        for (int64_t i = size - 1; i >= 0; --i) {
            out << stack[i] << ' ';
        }
        out << std::endl;
    }
private:
    T* stack;
    size_t size;
    size_t capacity;
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

    return 0;
}