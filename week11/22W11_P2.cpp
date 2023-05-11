//
//  22_w11_p2.cpp
//  week11BinarySearchTree
//
//  Created by ���ֹ� on 2023/05/09.
//

/*
 ���� Ž�� Ʈ�� ���� ��,
 �־��� ��ɾ �����ϴ� ���α׷� ����
 insert x, delete x, min x, height x
 */

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

    /*
     ���ڰ��� ���� ��带 ã�� Ž�� �Լ�
     */
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

    /*
     depth�� �����ִ� �Լ�
     */
    void depth(Node* node) {
        Node* curNode = node;
        int depth = 0;

        while (curNode != root) {
            curNode = curNode->par;
            depth++;
        }
        cout << depth << "\n";
    }

    /*
     ���ڰ��� ���� ��带 BST�� �߰��ϴ� �Լ�
     */
    void insert(int data) {
        // 1. ���ο� ��� ����
        Node* newNode = new Node(data);

        // 2. ������ ��ġ Ž��
        if (root == nullptr) { // Ʈ���� ����ִ� ���, ��Ʈ�� �������ְ� ����
            root = newNode;
            return;
        }

        Node* curNode = root; // ��Ʈ���� Ž�� ����
        Node* parNode = root->par;

        while (curNode != nullptr) {
            if (data < curNode->data) { // ���� ����Ʈ���� �̵�
                parNode = curNode;
                curNode = curNode->left;
            }
            else { // ������ ����Ʈ���� �̵�
                parNode = curNode;
                curNode = curNode->right;
            }
        }

        // 3. ��ġ(curNode)�� ��� ����; �θ�� �ڽ� ���� �������ֱ�
        newNode->par = parNode;
        if (data < parNode->data) {
            parNode->left = newNode;
        }
        else {
            parNode->right = newNode;
        }
    }

    /*
     ���ڰ��� ���� ��带 BST���� ã�Ƽ� �����ϴ� �Լ�
     */
    void remove(int data) {
        // 1. ������ ����� ��ġ�� ã��
        Node* node = search(data);
        Node* parNode = node->par;

        // 2-1. �ڽ� 0���� ���; �׳� ����
        if (node->left == nullptr && node->right == nullptr) {
            if (node == root) { // ��Ʈ �����ϴ� ��� ��Ʈ nullptr�� ����
                this->root = nullptr;
            }
            else {
                if (node == parNode->left) {
                    parNode->left = nullptr;
                }
                else {
                    parNode->right = nullptr;
                }
            }
            // 2-2. �ڽ� 1���� ���; ������ ����� �ڽ� ��带 ������ ����� ��ġ�� �̵�
        }
        else if (node->left == nullptr || node->right == nullptr) {
            Node* child = (node->left != nullptr) ? node->left : node->right;

            if (node == root) { // ��Ʈ �����ϴ� ��� ��Ʈ�� �ڽ����� ���� ����
                this->root = child;
            }
            else {
                if (node == parNode->left) {
                    parNode->left = child;
                    child->par = parNode;
                }
                else {
                    parNode->right = child;
                    child->par = parNode;
                }
            }
            // 2-3. �ڽ� 2���� ���; ������ ����Ʈ������ min�� ��带 ������ ����� ��ġ�� �̵�
        }
        else if (node->left != nullptr && node->right != nullptr) {
            Node* succ = node->right;
            Node* succPar = node;

            while (succ->left != nullptr) { // ������ ����Ʈ������ min�� = ���� ���� �ϴܿ� �ִ� ���
                succPar = succ; // ���� ����Ʈ���� ��� �̵�
                succ = succ->left;
            }

            if (succ == succPar->left) {
                succPar->left = succ->right;
            }
            else {
                succPar->right = succ->right;
            }

            node->data = succ->data;
            node = succ;
        }
        delete node;
    }

    /*
     k��°�� ���� ������ ���
     */
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

    /*
     ���ڰ��� ��Ʈ�� �ϴ� ����Ʈ���� ����(������ ���� �� �ִ밪)�� ���
     */
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