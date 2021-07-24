/*
    Doubly Linked List
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
class DoublyLinkedList final {
public:
    DoublyLinkedList() : _size(0), _head(nullptr), _tail(nullptr) {}
    size_t getSize() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    T& at(const int64_t& index) const {
        if (index < 0 || index >= _size)
            throw doublyLinkedListOutOfBound;
        Node* cur;
        if (index < _size / 2) {
            cur = _head.get();
            for (size_t i = 0; i < index; ++i) {
                cur = cur->_next.get();
            }
        } else {
            cur = _tail;
            for (size_t i = 0; i > index; --i) {
                cur = cur->_prev;
            }
        }
        return cur->_value;
    }
    int64_t find(const T& value) const {
        if (empty())
            throw doublyLinkedListEmpty;
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
            throw doublyLinkedListOutOfBound;
        if (index == 0) {
            _head = std::make_unique<Node>(value, nullptr, std::move(_head));
            if (empty())
                _tail = _head.get();
        } else if (index == _size) {
            _tail->_next = std::make_unique<Node>(value, _tail);
            _tail = _tail->_next.get();
        } else {
            Node* cur;
            if (index < _size / 2) {
                cur = _head.get();
                for (size_t i = 0; i < index - 1; ++i) {
                    cur = cur->_next.get();
                }
            } else {
                cur = _tail;
                for (size_t i = 0; i > index - 1; --i) {
                    cur = cur->_prev;
                }
            }
            cur->_next = std::make_unique<Node>(value, cur, std::move(cur->_next));
            cur->_next->_next->_prev = cur->_next.get();
        }
        ++_size;
    }
    T remove(const int64_t& index) {
        if (empty())
            throw doublyLinkedListEmpty;
        if (index < 0 || index >= _size)
            throw doublyLinkedListOutOfBound;
        T deleted;
        if (index == 0) {
            deleted = _head->_value;
            _head = std::move(_head->_next);
            (_size == 1) ? (_tail) : (_head->_prev) = nullptr;
        } else if (index == _size - 1) {
            deleted = _tail->_value;
            _tail->_next = nullptr;
            _tail = _tail->_prev;
        } else {
            Node* cur;
            if (index < _size / 2) {
                cur = _head.get();
                for (size_t i = 0; i < index - 1; ++i) {
                    cur = cur->_next.get();
                }
            } else {
                cur = _tail;
                for (size_t i = 0; i > index - 1; --i) {
                    cur = cur->_prev;
                }
            }
            cur->_next = std::move(cur->_next->_next);
            cur->_next->_prev = cur;
            deleted = cur->_value;
        }
        --_size;
        return deleted;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty())
            throw doublyLinkedListEmpty;
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
        explicit Node(const T& value, Node* prev = nullptr, std::unique_ptr<Node>&& next = nullptr) : _value(value), _prev(prev), _next(std::move(next)) {}
    private:
        T _value;
        Node* _prev;
        std::unique_ptr<Node> _next;
        friend class DoublyLinkedList<T>;
    };
    size_t _size;
    std::unique_ptr<Node> _head;
    Node* _tail;
    class DoublyLinkedListEmptyException : public std::exception {
        const char* what() const throw() {
            return "Doubly linked list is empty";
        }
    } doublyLinkedListEmpty;
    class DoublyLinkedListOutOfBoundException : public std::exception {
        const char* what() const throw() {
            return "Doubly linked list index out of bound";
        }
    } doublyLinkedListOutOfBound;
};

int main() {
    DoublyLinkedList<int> list;
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