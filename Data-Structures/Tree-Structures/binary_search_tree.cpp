/*
    Binary Search Tree
    -----------------------------------------------------------------------
    |             Operations Allowed at Arbitrary Positions               |
    -----------------------------------------------------------------------
    |   Access   |      Search     |     Insertion    |      Deletion     |
    -----------------------------------------------------------------------
    | No Support | Θ(log(n))  O(n) |  Θ(log(n))  O(n) |  Θ(log(n))  O(n) |
    -----------------------------------------------------------------------
*/
#include <exception>
#include <iostream>
#include <memory>

template<typename T>
class BinarySearchTree final {
public:
    BinarySearchTree() : _size(0), _root(nullptr) {}
    size_t getSize() const {
        return _size;
    }
    bool empty() const {
        return _size == 0;
    }
    bool contains(const T& value) const {
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
            while (cur != nullptr) {
                if (value < cur->_value) {
                    if (cur->_left != nullptr) {
                        cur = cur->_left.get();
                    } else {
                        cur->_left = std::make_unique<Node>(value);
                        cur = nullptr;
                    }
                } else {
                    if (cur->_right != nullptr) {
                        cur = cur->_right.get();
                    } else {
                        cur->_right = std::make_unique<Node>(value);
                        cur = nullptr;
                    }
                }
            }
        }
        ++_size;
    }
    bool remove(const T& value) {
        if (empty())
            throw binarySearchTreeEmpty;
        // Find node for removal
        NodeType curType = Root;
        Node* cur = _root.get(), * parent = _root.get();
        while (cur != nullptr) {
            if (value < cur->_value) {
                parent = cur;
                curType = LeftChild;
                cur = cur->_left.get();
            } else if (value < cur->_value) {
                parent = cur;
                curType = RightChild;
                cur = cur->_right.get();
            } else {
                break;
            }
        }
        // Node doesn't exist
        if (cur == nullptr)
            return false;
        // Node has two children
        if (cur->_left != nullptr && cur->_right != nullptr) {
            // Find the left successor
            NodeType leftSuccessorType = LeftChild;
            Node* leftSuccessor = cur->_left.get(), * leftSuccessorParent = cur;
            if (leftSuccessor->_right != nullptr)
                leftSuccessorType = RightChild;
            while (leftSuccessor->_right != nullptr) {
                leftSuccessorParent = leftSuccessor;
                leftSuccessor = leftSuccessor->_right.get();
            }
            cur->_value = leftSuccessor->_value;
            // Remove the left successor
            ((leftSuccessorType == LeftChild) ? (leftSuccessorParent->_left) : (leftSuccessorParent->_right)) = nullptr;
        }
        // Node has either one or no children
        else if (cur->_left != nullptr && cur->_right == nullptr) {
            (curType == Root) ? (_root) : ((curType == LeftChild) ? (parent->_left) : (parent->_right)) = std::move(cur->_left);
        } else if (cur->_left == nullptr && cur->_right != nullptr) {
            (curType == Root) ? (_root) : ((curType == LeftChild) ? (parent->_left) : (parent->_right)) = std::move(cur->_right);
        } else {
            (curType == Root) ? (_root) : ((curType == LeftChild) ? (parent->_left) : (parent->_right)) = nullptr;
        }
        --_size;
        return true;
    }
    enum class TraversalType {
        PreOrder = 0, InOrder = 1, PostOrder = 2
    };
    void print(const TraversalType& traversalType, std::ostream& out = std::cout) const {
        if (empty())
            throw binarySearchTreeEmpty;
        switch (traversalType) {
            case TraversalType::PreOrder:
                _traversePreOrder(_root, out);
                break;
            case TraversalType::InOrder:
                _traverseInOrder(_root, out);
                break;
            case TraversalType::PostOrder:
                _traversePostOrder(_root, out);
        }
        std::cout << std::endl;
    }
private:
    enum NodeType {
        Root = 0, LeftChild = 1, RightChild = 2
    };
    struct Node {
    public:
        explicit Node(const T& value) : _value(value), _left(nullptr), _right(nullptr) {}
    private:
        T _value;
        std::unique_ptr<Node> _left;
        std::unique_ptr<Node> _right;
        friend class BinarySearchTree<T>;
    };
    size_t _size;
    std::unique_ptr<Node> _root;
    void _traversePreOrder(const std::unique_ptr<Node>& cur, std::ostream& out = std::cout) const {
        out << cur->_value << ' ';
        if (cur->_left != nullptr)
            _traversePreOrder(cur->_left, out);
        if (cur->_right != nullptr)
            _traversePreOrder(cur->_right, out);
    }
    void _traverseInOrder(const std::unique_ptr<Node>& cur, std::ostream& out = std::cout) const {
        if (cur->_left != nullptr)
            _traverseInOrder(cur->_left, out);
        out << cur->_value << ' ';
        if (cur->_right != nullptr)
            _traverseInOrder(cur->_right, out);
    }
    void _traversePostOrder(const std::unique_ptr<Node>& cur, std::ostream& out = std::cout) const {
        if (cur->_left != nullptr)
            _traversePostOrder(cur->_left, out);
        if (cur->_right != nullptr)
            _traversePostOrder(cur->_right, out);
        out << cur->_value << ' ';
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
        << tree.contains(7) << ' '
        << tree.remove(3) << ' '
        << tree.empty() << std::endl;
    tree.print(BinarySearchTree<int>::TraversalType::PreOrder);
    tree.print(BinarySearchTree<int>::TraversalType::InOrder);
    tree.print(BinarySearchTree<int>::TraversalType::PostOrder);

    return EXIT_SUCCESS;
}