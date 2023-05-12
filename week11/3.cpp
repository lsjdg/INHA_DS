#include <iostream>
using namespace std;

int c, k;

class Node {
private:
    int data;
    Node* par;
    Node* left;
    Node* right;

public:
    Node(int d) {
        data = d;
        par = left = right = nullptr;
    }
    friend class BST;
};

class BST {
public:
    Node* root = nullptr;
 

    Node* search(int data) {
        Node* curNode = root;
        while (curNode != nullptr) {
            if (data == curNode->data) {
                return curNode;
            }
            else if (data < curNode->data) {
                curNode = curNode->left;
            }
            else if (data > curNode->data) {
                curNode = curNode->right;
            }
        }
        return nullptr;
    }


    void depth(Node* node) {
        Node* curNode = node;
        int depth = 0;

        while (curNode != root) {
            curNode = curNode->par;
            depth++;
        }
        cout << depth << "\n";
    }


    void insert(int data) {

        Node* newNode = new Node(data);


        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curNode = root;
        Node* parNode = root->par;

        while (curNode != nullptr) {
            if (data < curNode->data) {
                parNode = curNode;
                curNode = curNode->left;
            }
            else {
                parNode = curNode;
                curNode = curNode->right;
            }
        }


        newNode->par = parNode;
        if (data < parNode->data) {
            parNode->left = newNode;
        }
        else {
            parNode->right = newNode;
        }
    }



    void remove(int key)
    {
        Node* delNode = search(key);
        if (delNode == NULL) return;

        Node* parNode = delNode->par;
        Node* childNode;

        if (delNode->left == NULL && delNode->right == NULL)
            childNode = NULL;
        else if (delNode->left == NULL && delNode->right != NULL)
            childNode = delNode->right;
        else if (delNode->left != NULL && delNode->right == NULL)
            childNode = delNode->left;
        else
        {
            childNode = delNode->right;
            while (childNode->left != NULL)
                childNode = childNode->left;
            delNode->data = childNode->data;
            delNode = childNode;
            parNode = delNode->par;
            childNode = delNode->right;
        }
        if (parNode == NULL)
        {
            root = childNode;
            root->par = NULL;
        }
        else if (delNode == parNode->left)
        {
            parNode->left = childNode;
            if (childNode != NULL) childNode->par = parNode;
        }
        else
        {
            parNode->right = childNode;
            if (childNode != NULL) childNode->par = parNode;
        }
        delete delNode;
    }


    void min(Node* node) {
        if (node == nullptr) return;

        min(node->left);
        c++;
        if (c == k) {
            cout << node->data << "\n";
            return;
        }
        min(node->right);
    }


    int height(Node* node) {
        if (node == nullptr)
            return -1;

        if (height(node->left) < height(node->right))
            return height(node->right) + 1;
        else
            return height(node->left) + 1;
    }

};

int main() {
    int numOfCmd;
    cin >> numOfCmd;

    BST* bst = new BST();

    while (numOfCmd--) {
        string cmd;
        int x;

        cin >> cmd >> x;

        if (cmd == "insert") {
            bst->insert(x);
            bst->depth(bst->search(x));
        }
        else if (cmd == "delete") {
            bst->depth(bst->search(x));
            bst->remove(x);
        }
        else if (cmd == "min") {
            k = x;
            c = 0;
            bst->min(bst->root);
        }
        else if (cmd == "height") {
            cout << bst->height(bst->search(x)) << "\n";
        }
    }
}