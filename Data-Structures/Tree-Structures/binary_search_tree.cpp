/*
    Binary Search Tree
    -----------------------------------------------------------------------
    |   Access   |      Search     |     Insertion    |      Deletion     |
    -----------------------------------------------------------------------
    | No Support | Θ(log(n))  O(n) |  Θ(log(n))  O(n) |  Θ(log(n))  O(n) |
    -----------------------------------------------------------------------
*/
#include <exception>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <cmath>

template<typename T>
class BinarySearchTree final {
public:
    BinarySearchTree() : _size(0), _root(nullptr) {}
    unsigned getSize() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    bool find(const T& value) const {
        if (empty())
            throw binarySearchTreeEmpty;
        Node* cur = _root.get();
        while (cur != nullptr) {
            if (value < cur->_value)
                cur = cur->_left.get();
            else if (value > cur->_value)
                cur = cur->_right.get();
            else
                return true;
        }
        return false;
    }
    void insert(const T& value) {
        if (empty()) {
            _root = std::make_unique<Node>(value);
        } else {
            Node* cur = _root.get();
            while (true) {
                if (value < cur->_value) {
                    if (cur->_left != nullptr) {
                        cur = cur->_left.get();
                    } else {
                        cur->_left = std::make_unique<Node>(value);
                        break;
                    }
                } else {
                    if (cur->_right != nullptr) {
                        cur = cur->_right.get();
                    } else {
                        cur->_right = std::make_unique<Node>(value);
                        break;
                    }
                }
            }
        }
        ++_size;
    }
    bool remove(const T& value) {
        if (empty())
            throw binarySearchTreeEmpty;
        Node* parent, * cur = _root.get();
        while (cur != nullptr) {
            if (value < cur->_value) {
                parent = cur;
                cur = cur->_left.get();
            } else if (value > cur->_value) {
                parent = cur;
                cur = cur->_right.get();
            } else {
                break;
            }
        }
        if (cur == nullptr)
            return false;
        if (cur->_left == nullptr && cur->_right == nullptr) {
            if (cur == _root.get())
                _root = nullptr;
            else if (cur == parent->_left.get())
                parent->_left = nullptr;
            else
                parent->_right = nullptr;
        } else if (cur->_left != nullptr && cur->_right == nullptr) {
            if (cur == _root.get())
                _root = std::move(cur->_left);
            else if (cur == parent->_left.get())
                parent->_left = std::move(cur->_left);
            else
                parent->_right = std::move(cur->_left);
        } else if (cur->_left == nullptr && cur->_right != nullptr) {
            if (cur == _root.get())
                _root = std::move(cur->_right);
            else if (cur == parent->_left.get())
                parent->_left = std::move(cur->_right);
            else
                parent->_right = std::move(cur->_right);
        } else {
            Node* rightSuccessor = cur->_right.get(), * rightSuccessorParent = cur;
            while (rightSuccessor->_left != nullptr) {
                rightSuccessorParent = rightSuccessor;
                rightSuccessor = rightSuccessor->_left.get();
            }
            cur->_value = rightSuccessor->_value;
            if (rightSuccessor == rightSuccessorParent->_left.get())
                rightSuccessorParent->_left = std::move(rightSuccessor->_right);
            else
                rightSuccessorParent->_right = std::move(rightSuccessor->_right);
        }
        --_size;
        return true;
    }
    bool isAVLBalanced() const {
        // Traverse Post-Order
        std::stack<Node*> s;
        Node* cur = _root.get();
        bool isAVLBalanced = true;
        int leftSubtreeHeight, rightSubtreeHeight;
        while (isAVLBalanced) {
            while (cur != nullptr) {
                s.emplace(cur);
                s.emplace(cur);
                cur = cur->_left.get();
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
            if (s.empty() == false && s.top() == cur) {
                cur = cur->_right.get();
            } else {
                // Check AVL Balance Condition
                if (cur->_left != nullptr || cur->_right != nullptr) {
                    leftSubtreeHeight = rightSubtreeHeight = 0;
                    if (cur->_left != nullptr)
                        leftSubtreeHeight = getHeight(cur->_left.get());
                    if (cur->_right != nullptr)
                        rightSubtreeHeight = getHeight(cur->_right.get());
                    if (std::abs(leftSubtreeHeight - rightSubtreeHeight) > 1)
                        isAVLBalanced = false;
                }
                cur = nullptr;
            }
        }
        return isAVLBalanced;
    }
    void traversePreOrder(std::ostream& out = std::cout) const {
        if (empty())
            throw binarySearchTreeEmpty;
        std::stack<Node*> s;
        Node* cur = _root.get();
        while (cur != nullptr || s.empty() == false) {
            while (cur != nullptr) {
                out << cur->_value << ' ';
                if (cur->_right.get() != nullptr)
                    s.emplace(cur->_right.get());
                cur = cur->_left.get();
            }
            if (s.empty() == false) {
                cur = s.top();
                s.pop();
            }
        }
        std::cout << std::endl;
    }
    void traverseInOrder(std::ostream& out = std::cout) const {
        if (empty())
            throw binarySearchTreeEmpty;
        std::stack<Node*> s;
        Node* cur = _root.get();
        while (cur != nullptr || s.empty() == false) {
            while (cur != nullptr) {
                s.emplace(cur);
                cur = cur->_left.get();
            }
            cur = s.top();
            s.pop();
            out << cur->_value << ' ';
            cur = cur->_right.get();
        }
        std::cout << std::endl;
    }
    void traversePostOrder(std::ostream& out = std::cout) const {
        if (empty())
            throw binarySearchTreeEmpty;
        std::stack<Node*> s;
        Node* cur = _root.get();
        while (true) {
            while (cur != nullptr) {
                s.emplace(cur);
                s.emplace(cur);
                cur = cur->_left.get();
            }
            if (s.empty())
                break;
            cur = s.top();
            s.pop();
            if (s.empty() == false && s.top() == cur) {
                cur = cur->_right.get();
            } else {
                out << cur->_value << ' ';
                cur = nullptr;
            }
        }
        std::cout << std::endl;
    }
private:
    struct Node {
    public:
        explicit Node(const T& value) : _value(value), _left(nullptr), _right(nullptr) {}
    private:
        T _value;
        std::unique_ptr<Node> _left;
        std::unique_ptr<Node> _right;
        friend class BinarySearchTree<T>;
    };
    unsigned _size;
    std::unique_ptr<Node> _root;
    unsigned getHeight(Node* cur) const {
        if (empty())
            throw binarySearchTreeEmpty;
        std::queue<Node*> q;
        q.emplace(cur);
        unsigned curLevelNodeCount, height = 0;
        while (true) {
            curLevelNodeCount = q.size();
            if (curLevelNodeCount == 0)
                break;
            ++height;
            while (curLevelNodeCount > 0) {
                Node* cur = q.front();
                q.pop();
                if (cur->_left != nullptr)
                    q.emplace(cur->_left.get());
                if (cur->_right != nullptr)
                    q.emplace(cur->_right.get());
                --curLevelNodeCount;
            }
        }
        return height;
    }
    class BinarySearchTreeEmptyException : public std::exception {
        const char* what() const throw() {
            return "Binary search tree is empty";
        }
    } binarySearchTreeEmpty;
};

int main() {
    BinarySearchTree<int> tree;
    tree.insert(3);
    tree.insert(7);
    std::cout << tree.getSize() << ' '
        << tree.isAVLBalanced() << ' '
        << tree.find(7) << ' '
        << tree.remove(3) << ' '
        << tree.empty() << std::endl;
    tree.traversePreOrder();
    tree.traverseInOrder();
    tree.traversePostOrder();

    return EXIT_SUCCESS;
}