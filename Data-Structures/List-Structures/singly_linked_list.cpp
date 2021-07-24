/*
    Singly Linked List
    --------------------------------------------------------
    |      Operations Allowed at Arbitrary Positions       |
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(n)  O(n) |  Θ(n)  O(n) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>
#include <memory>

template<typename T>
class SinglyLinkedList final {
public:
    SinglyLinkedList() : _size(0), _head(nullptr) {}
    size_t getSize() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    T& at(const int64_t& index) const {
        if (index < 0 || index >= _size)
            throw singlyLinkedListOutOfBound;
        Node* cur = _head.get();
        for (size_t i = 0; i < index; ++i) {
            cur = cur->_next.get();
        }
        return cur->_value;
    }
    int64_t find(const T& value) const {
        if (empty())
            throw singlyLinkedListEmpty;
        Node* cur = _head.get();
        for (size_t i = 0; i < _size; ++i) {
            if (cur->_value == value)
                return i;
            cur = cur->_next.get();
        }
        return -1;
    }
    void insert(const T& value, const int64_t& index) {
        if (index < 0 || index > _size)
            throw singlyLinkedListOutOfBound;
        if (index == 0) {
            _head = std::make_unique<Node>(value, std::move(_head));
        } else {
            Node* cur = _head.get();
            for (size_t i = 0; i < index - 1; ++i) {
                cur = cur->_next.get();
            }
            cur->_next = std::make_unique<Node>(value, std::move(cur->_next));
        }
        ++_size;
    }
    T remove(const int64_t& index) {
        if (empty())
            throw singlyLinkedListEmpty;
        if (index < 0 || index >= _size)
            throw singlyLinkedListOutOfBound;
        T deleted;
        if (index == 0) {
            deleted = _head->_value;
            _head = std::move(_head->_next);
        } else {
            Node* cur = _head.get();
            for (size_t i = 0; i < index - 1; ++i) {
                cur = cur->_next.get();
            }
            deleted = cur->_next->_value;
            cur->_next = std::move(cur->_next->_next);
        }
        --_size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw singlyLinkedListEmpty;
        Node* cur = _head.get();
        for (size_t i = 0; i < _size; ++i) {
            out << cur->_value << ' ';
            cur = cur->_next.get();
        }
        out << std::endl;
    }
private:
    struct Node {
    public:
        explicit Node(const T& value, std::unique_ptr<Node>&& next = nullptr) : _value(value), _next(std::move(next)) {}
    private:
        T _value;
        std::unique_ptr<Node> _next;
        friend class SinglyLinkedList<T>;
    };
    size_t _size;
    std::unique_ptr<Node> _head;
    class SinglyLinkedListEmptyException : public std::exception {
        const char* what() const throw() {
            return "Singly linked list is empty";
        }
    } singlyLinkedListEmpty;
    class singlyLinkedListOutOfBoundException : public std::exception {
        const char* what() const throw() {
            return "Singly linked list index out of bound";
        }
    } singlyLinkedListOutOfBound;
};

int main() {
    SinglyLinkedList<int> list;
    list.insert(3, 0);
    list.insert(7, 0);
    std::cout << list.getSize() << ' '
        << list.find(7) << ' '
        << list.at(0) << ' '
        << list.remove(1) << ' '
        << list.empty() << std::endl;
    list.print();

    return EXIT_SUCCESS;
}