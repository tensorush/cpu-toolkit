/*
    Doubly Linked List
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class DoublyLinkedList final {
    // TODO: Fix this implementation
public:
    DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    ~DoublyLinkedList() { clear(); }
    size_t get_size() const {
        return size;
    }
    bool empty() const {
        return (size == 0);
    }
    T operator [] (const int64_t& index) const {
        if (index < 0 || index >= size) throw list_out_of_bound;
        Node<T>* cur;
        if (index < size / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (size_t i = size; i > index; --i) {
                cur = cur->prev;
            }
        }
        return cur->value;
    }
    int64_t find(const T& object) const {
        Node<T>* cur = head;
        for (size_t i = 0; i < size; ++i) {
            if (cur->value == object) return i;
            cur = cur->next;
        }
        return -1;
    }
    void insert(const T object, const int64_t& index) {
        if (index < 0 || index > size) throw list_out_of_bound;
        Node<T>* newNode;
        newNode->value = object;
        if (index == 0) {
            if (empty()) {
                head = new Node<T>(object, nullptr, nullptr);
                tail = head;
            } else {
                head->prev = new Node<T>(object, nullptr, head);
                head = head->prev;
            }
        } else if (index == size) {
            tail->next = new Node<T>(object, tail, nullptr);
            tail = tail->next;
        } else {
            Node<T>* cur = head;
            for (size_t i = 0; i < index - 1; ++i) {
                cur = cur->next;
            }
            Node<T>* newNode = new Node<T>(object, cur, cur->next);
            cur->next->prev = newNode;
            cur->next = newNode;
        }
        ++size;
    }
    T remove(const int64_t& index) {
        if (empty()) throw list_empty;
        if (index < 0 || index >= size) throw list_out_of_bound;
        T deleted;
        if (index == 0) {
            deleted = head->value;
            head = head->next;
            (empty())?(tail = nullptr):(head->prev = nullptr);
        } else if (index == size - 1) {
            deleted = tail->value;
            tail = tail->prev;
            (empty())?(head = nullptr):(tail->next = nullptr);
        } else {
            size_t i;
            Node<T>* cur;
            if (index < size / 2) {
                for (i = 0, cur = head; i != index; ++i) {
                    cur = cur->next;
                }
            } else {
                for (i = size - 1, cur = tail; i != index; --i) {
                    cur = cur->prev;
                }
            }
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
            deleted = cur->value;
            cur->prev = cur->next = nullptr;
            cur = nullptr;
        }
        --size;
        return deleted;
    }
    void clear() {
        Node<T>* cur = head;
        while (cur != nullptr) {
            Node<T>* node = cur->next;
            delete cur;
            cur = node;
        }
        head = tail = cur = nullptr;
        size = 0;
    }
    void print(std::ostream& out = std::cout) const {
        if (empty()) throw list_empty;
        Node<T>* cur = head;
        for (size_t i = 0; i < size; ++i) {
            out << cur->value << ' ';
            cur = cur->next;
        }
        out << std::endl;
    }
private:
    template <typename U = T>
    class Node final {
    public:
        Node() : value(0), prev(nullptr), next(nullptr) {}
        Node(const U& _value, Node<U>* _prev, Node<U>* _next) : value(_value), prev(_prev), next(_next) {}
    private:
        U value;
        Node<U>* prev;
        Node<U>* next;
        friend DoublyLinkedList<U>;
    };
    Node<T>* head;
    Node<T>* tail;
    size_t size;
    class LinkedListEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "Doubly Linked List is empty";
        }
    } list_empty;
    class LinkedListOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "Doubly Linked List index out of bound";
        }
    } list_out_of_bound;
};

int main() {
    DoublyLinkedList<int> list;
    list.insert(3, 0);
    list.insert(7, 0);
    std::cout << list.get_size() << ' '
              << list.find(7) << ' '
              << list[0] << ' '
              << list.remove(1) << ' '
              << list.empty() << std::endl;
    list.print();

    return EXIT_SUCCESS;
}