#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
            return;
        }
        if (value < node->data) {
            insert(node->left, value);
        } else if (value > node->data) {
            insert(node->right, value);
        }
    }

    bool search(Node* node, int value, vector<int>& path) {
        if (node == nullptr) {
            return false;
        }
        path.push_back(node->data);
        if (node->data == value) {
            return true;
        }
        if (value < node->data) {
            return search(node->left, value, path);
        } else {
            return search(node->right, value, path);
        }
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {

            
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* findMax(Node* node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    void inOrder(Node* node, vector<int>& nodes) {
        if (node != nullptr) {
            inOrder(node->left, nodes);
            nodes.push_back(node->data);
            inOrder(node->right, nodes);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void search(int value) {
        vector<int> path;
        if (search(root, value, path)) {
            cout << "Found: ";
        } else {
            cout << "Not found: ";
        }
        for (int val : path) {
            cout << val << " → ";
        }
        cout << (path.empty() ? "" : "search key not found") << endl;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void display() {
        vector<int> nodes;
        inOrder(root, nodes);
        cout << "BST nodes are: ";
        for (int val : nodes) {
            cout << val << " ";
        }
        cout << endl;
    }

    void findMin() {
        Node* minNode = findMin(root);
        if (minNode) {
            cout << "Node with the smallest value: " << minNode->data << endl;
        }
    }

    void findMax() {
        Node* maxNode = findMax(root);
        if (maxNode) {
            cout << "Node with the largest value: " << maxNode->data << endl;
        }
    }
};

int main() {
    BinarySearchTree bst;

    //put in node
    vector<int> values = {5, 3, 1, 4, 7, 8};
    for (int value : values) {
        bst.insert(value);
    }
    bst.display();

    //delete node
    bst.deleteNode(4);
    cout << "Node 4 has been deleted" << endl;
    bst.display();

    bst.insert(2);
    cout << "Node 2 has been inserted" << endl;
    bst.display();

    bst.insert(7);
    cout << "Node 7 is a duplicate node. Cannot insert Node 7 again" << endl;
    bst.display();

    bst.insert(6);
    cout << "Node 6 has been inserted" << endl;
    bst.display();

    bst.deleteNode(7);
    cout << "Node 7 has been deleted" << endl;
    bst.display();

    bst.findMin();
    bst.display();

    bst.search(9);

    return 0;
}
