#include <iostream>
#include <vector>
using namespace std;
int c{ 0 };
class Node
{
public:
	Node* parent;
	Node* left;
	Node* right;
	int value;
	
	Node(int value)
	{
		this->value = value;
		parent = left = right = nullptr;
	}
};

class BST
{
public:
	Node* root = nullptr;
	Node* search(int x)
	{
		Node* curNode = root;
		while (curNode != nullptr)
		{
			if (curNode->value == x)
				return curNode;
			else if (x < curNode->value)
				curNode = curNode->left;
			else if (x > curNode->value)
				curNode = curNode->right;
		}
		return nullptr;
	}
	void insert(int x)
	{
		Node* newNode = new Node(x);
		if (root == nullptr)
		{
			root = newNode;
			return;
		}
		Node* curNode = root;
		Node* parNode = curNode->parent;
		while (curNode != nullptr)
		{
			parNode = curNode;
			if (x < curNode->value)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		newNode->parent = parNode;
		if (x > parNode->value)
			parNode->right = newNode;
		else
			parNode->left = newNode;
	}
	void inOrder(Node* v)
	{
		if (v == nullptr)
			return;
		inOrder(v->left);
		c++;
		inOrder(v->right);
	}
	int subTreeHeight(int x)
	{
		Node* curNode = search(x)->right;
		if (curNode == nullptr)
			return 0;
		inOrder(curNode);
		return c;
	}
};

int main()
{
	int nodes, test;
	cin >> nodes >> test;
	BST bst;
	while (nodes--)
	{
		int x;
		cin >> x;
		bst.insert(x);
	}
	while (test--)
	{
		int a, b;
		cin >> a >> b;
		c = 0;
		int aSize = bst.subTreeHeight(a);
		c = 0;
		int bSize = bst.subTreeHeight(b);
		cout << abs(aSize - bSize) << '\n';
	}
}