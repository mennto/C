#include <iostream>
#include <chrono>
using namespace std;

template <typename T>
class binary {
public:
    binary(){}

    binary(T key) {
        this->key = key;
        left = nullptr;
        right = nullptr;
    }

    ~binary() {
       /* if (size_ == 1)
            drop();
        --size_;*/
    }

    //wrap to insertKey
    int insert(T key) {
        if (size_ == 0) {
            root->key = key;
            ++size_;
            return 1;
        }
        insertKey(root, key);
        return 1;
    }   

    //find and remove element of collection if it exist
    int remove(T key) {
        binary<T>* buf = searchKey(root, key);
        if (buf != nullptr) {
            removeKey(buf, key);
            return 1;
        }

        return 0;
    }

    //wrap to search
    binary<T>* search(T key) {
        return searchKey(root, key);
    }

    //wrap to getMaxKey
    T getMax() {
        if (root != nullptr)
            return getMaxKey(root);
    }

    //wrap to getMinKey
    T getMin() {
        if (root != nullptr)
            return getMinKey(root);
    }

    //wrap to deleteTree
    void drop() {
        deleteTree(root);
    }

    //wrap to printData
    void print() {
        printData(root);
    }

    //getters
    T getKey() { return key; }
    size_t size() { return size_; }

    //private methods
private:
    //print collection
    int printData(binary<T>* root) {
        if (root == nullptr) {
            return 1;
        }   
        cout << root->key << endl;
        printData(root->left);
        printData(root->right);
    }

    //delete collection
    int deleteTree(binary<T>* root) {
        if (root == nullptr) {
            return 1;
        }
        deleteTree(root->left);
        deleteTree(root->right);

        size_ = 0;
        delete root;
    }

    //get min value 
    T getMinKey(binary<T>* node) {
        if (node->left != nullptr)
            return getMinKey(node->left);
        return node->key;
    }

    //get max value 
    T getMaxKey(binary<T>* node) {
        if (node->right != nullptr)
            return getMaxKey(node->right);
        return node->key;
    }

    //delete element 
    int removeKey(binary<T>*& node, T key) {
        if (node->left == nullptr && node->right == nullptr) {
            delete this;
        }
        if (node->left == nullptr || node->right == nullptr) {
            if (node->left == nullptr) {
                node->key = node->right->key;
                delete node->right;
            }
            else {
                node->key = node->left->key;
                delete node->left;
            }
        }
        if (node->left != nullptr && node->right != nullptr) {
            binary<T>* buf;
            while (node->left != nullptr) {
                return getMinKey(node->left);
            }
            //getMaxKey(node->right);
        }

    }

    //search element
    binary<T>* searchKey(binary<T>*& node, T key) {
        if (node == nullptr)
            return nullptr;
        if (node->key == key)
            return node;
        return key < node->key ? searchKey(node->left, key) : searchKey(node->right, key);
    }

    //insert value
    int insertKey(binary<T>*& node, T key) {
        if (key < node->key) {
            if (node->left != nullptr)
                insertKey(node->left, key);
            else {
                node->left = new binary<T>(key);
                ++size_;
                return 1;
            }
        }
        if (key > node->key) {
            if (node->right != nullptr)
                insertKey(node->right, key);
            else {
                node->right = new binary<T>(key);
                ++size_;
                return 1;
            }
        }
        return 1;
    }

    //private fields
private:
    T key;
    binary<T>* left;
    binary<T>* right;  
    
    static size_t size_;
    static binary<T>* root;
};

//initialization static field root
template <typename T>
binary<T>* binary<T>::root = new binary<T>;

//initialization static field size_
template <typename T>
size_t binary<T>::size_ = 0;

int main() {
    binary<int> myTree;
    myTree.insert(1);
    myTree.insert(-5);
    myTree.insert(-2);
    myTree.insert(-9);
    myTree.insert(5);
    myTree.insert(3);

   /* if (myTree.search(-9) != nullptr) {
        cout << myTree.search(-9)->getKey();
    }*/

    //cout<<myTree.size()<<endl;

    //myTree.print();

    cout<<myTree.getMin();

    myTree.drop();

    return 0;
}