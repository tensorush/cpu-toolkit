/*
    Linked List
    --------------------------------------------------------
    |   Access   |   Search   |  Insertion  |   Deletion   |
    --------------------------------------------------------
    | Θ(n)  O(n) | Θ(n)  O(n) |  Θ(1)  O(1) |  Θ(1)  O(1) |
    --------------------------------------------------------
*/
#include <exception>
#include <iostream>

template<typename T>
class LinkedList {
    // Implementation is incomplete
    // TODO: Dynamic Memory Allocation
public:
    LinkedList() : size(0), head(new Node<T>) {}
    ~LinkedList() {
        while(!empty()) remove(0);
        delete head;
    }
    size_t get_size() const {
        return size;
    }
    bool empty() const {
        return head->next == NULL;
    }
    T operator [] (const int64_t& index) const {
        if (index < 0 || index >= size) throw list_out_of_bound;
        size_t mid = size / 2;
        Node<T>* cur;
        if (index < mid) {
            cur = head;
            for (size_t i = 0; i < index; ++i) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (size_t i = size; i > mid; --i) {
                cur = cur->prev;
            }
        }
        return cur->value;
    }
    int64_t find(const T& object) const {
        Node<T>* cur = head;
        for (int64_t i = 0; i < size; ++i) {
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
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else if (index == size) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        } else {
            Node<T>* cur = head;
            for (size_t i = 0; i < index; ++i) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            newNode->prev = cur;
            cur->next = newNode;
            newNode->next->prev = newNode;
        ++size;
        }
    }
    T remove(const int64_t& index) {
        if (index < 0 || index >= size) throw list_out_of_bound;
        T deleted;
        if (index == 0) {
            deleted = head->value;
            head = head->next;
            head->prev = NULL;
        } else if (index == size - 1) {
            deleted = tail->value;
            tail = tail->prev;
            tail->next = NULL;
        } else {
            Node<T>* cur = head;
            for (size_t i = 0; i < index; ++i) {
                cur = cur->next;
            }
            deleted = cur->next->value;
            cur->next = cur->next->next;
            cur->next->prev = cur;
        }
        --size;
        return deleted;
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
    template<typename T>
    struct Node {
        T value;
        Node<T>* next = NULL;
        Node<T>* prev = NULL;
    };
    Node<T>* head;
    Node<T>* tail;
    int64_t size;
    class LinkedListEmptyException : public std::exception {
        virtual const char* what() const throw() {
            return "LinkedList is empty";
        }
    } list_empty;
    class LinkedListOutOfBoundException : public std::exception {
        virtual const char* what() const throw() {
            return "LinkedList index out of bound";
        }
    } list_out_of_bound;
};

int main() {
    LinkedList<int> list;
    list.insert(3, 0);
    list.insert(7, 0);
    std::cout << list.get_size() << ' '
              << list[0] << ' '
              << list.remove(1) << ' '
              << list.empty() << std::endl;
    list.print();

    return 0;
}