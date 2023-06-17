#include <iostream>
#include <vector>
using namespace std;
int c, k;
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
			if (x == curNode->value)
				return curNode;
			else if (x < curNode->value)
				curNode = curNode->left;
			else
				curNode = curNode->right;
		}
		return nullptr;
	}
	int depth(Node* v)
	{
		int d{ 0 };
		Node* curNode = v;
		while (curNode != root)
		{
			curNode = curNode->parent;
			d++;
		}
		return d;
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
	void remove(int x)
	{
		Node* curNode = search(x);
		if (curNode == nullptr)
			return;
		Node* parNode = curNode->parent;
		Node* childNode;
		if (curNode->left == nullptr && curNode->right == nullptr)
			childNode = nullptr;
		else if (curNode->left != nullptr && curNode->right == nullptr)
			childNode = curNode->left;
		else if (curNode->left == nullptr && curNode->right != nullptr)
			childNode = curNode->right;
		else
		{
			childNode = curNode->right;
			while (childNode->left != nullptr)
				childNode = childNode->left;
			curNode->value = childNode->value;
			curNode = childNode;
			parNode = curNode->parent;
			childNode = curNode->right;
		}

		if (parNode == nullptr)
		{
			root = childNode;
			root->parent = nullptr;
		}
		else if (curNode == parNode->left)
		{
			parNode->left = childNode;
			if (childNode != nullptr)
				childNode->parent = parNode;
		}
		else
		{
			parNode->right = childNode;
			if (childNode != nullptr)
				childNode->parent = parNode;
		}
		delete curNode;
	}
	void min(Node* node) 
	{
		if (node == nullptr)
			return;
		min(node->left);
		c++;
		if (k == c) {
			cout << node->value << '\n';
			return;
		}
		min(node->right);
	}
	int height(Node* v)
	{
		if (v == nullptr) return -1;
		if (height(v->left) > height(v->right))
			return height(v->left) + 1;
		else
			return height(v->right) + 1;
	}
};

int main()
{
	int test, x;
	cin >> test;
	BST bst;
	while (test--)
	{
		string s;
		cin >> s;
		if (s == "insert")
		{
			cin >> x;
			bst.insert(x);
			cout << bst.depth(bst.search(x)) << '\n';
		}
		else if (s == "delete")
		{
			cin >> x;
			cout << bst.depth(bst.search(x)) << '\n';
			bst.remove(x);
		}
		else if (s == "min")
		{
			cin >> k;
			c = 0;
			bst.min(bst.root);
		}
		else if (s == "height")
		{
			cin >> x;
			cout << bst.height(bst.search(x)) << '\n';
		}
	}
}