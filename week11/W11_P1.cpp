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
	void inOrder(Node* startNode)
	{
		if (startNode == nullptr)
			return;
		inOrder(startNode->left);
		c++;
		inOrder(startNode->right);
	}
	int subTreeSize(int x)
	{
		Node* startNode = search(x)->left;
		if (startNode == nullptr)
			return 0;
		inOrder(startNode);
		return c;
	}
};

int main()
{
	int nodes, test;
	cin >> nodes >> test;
	BST bst = BST();
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
		int aSize = bst.subTreeSize(a);
		c = 0;
		int bSize = bst.subTreeSize(b);
		c = 0;
		cout << aSize + bSize << '\n';
	}
}