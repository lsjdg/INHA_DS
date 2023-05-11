#include <iostream>
#include <vector>
using namespace std;

int countNode;
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
			else if (x > curNode->value)
				curNode = curNode->right;
			else if (x < curNode->value)
				curNode = curNode->left;
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
		Node* parentNode = root->parent;
		while (curNode != nullptr)
		{
			if (x < curNode->value)
			{
				parentNode = curNode;
				curNode = curNode->left;
			}
			else
			{
				parentNode = curNode;
				curNode = curNode->right;
			}
		}
		newNode->parent = parentNode;
		if (x < parentNode->value)
			parentNode->left = newNode;
		else
			parentNode->right = newNode;
	}
	void remove(int x)
	{
		Node* target = search(x);
		Node* parentNode = target->parent;

		if (target->left == nullptr && target->right == nullptr)
		{
			if (target == root)
				root = nullptr;
			else
			{
				if (target == parentNode->left)
					parentNode->left = nullptr;
				else
					parentNode->right = nullptr;
			}
		}
		else if (target->left == nullptr || target->right == nullptr)
		{
			Node* childNode = target->left != nullptr
				? target->left : target->right;
			if (target == root)
				this->root = childNode;
			else
			{
				if (target == parentNode->left)
				{
					parentNode->left = childNode;
					childNode->parent = parentNode;
				}
				else
				{
					parentNode->right = childNode;
					childNode->parent = parentNode;
				}
			}
		}
		else if (target->left != nullptr && target->right != nullptr)
		{
			Node* succ = target->right;
			Node* succPar = succ->parent;
			while (succ->left != nullptr)
			{
				succPar = succ;
				succ = succ->left;
			}
			if (succ == succPar->left)
				succPar->left = succ->right;
			else
				succPar->right = succ->right;
			target->value = succ->value;
			target = succ;
		}
		delete target;
	}
	void countSubTreeNode(Node* v)
	{
		if (v == nullptr) return;
		countSubTreeNode(v->left);
		countNode++;
		countSubTreeNode(v->right);
	}
};

int main()
{
	int test;
	cin >> test;

	BST bst = BST();

	while (test--)
	{
		string s;
		int x;
		cin >> s;

		if (s == "insert")
		{
			cin >> x;
			bst.insert(x);
		}
		else if (s == "delete")
		{
			cin >> x;
			bst.remove(x);
		}
		else if (s == "sub")
		{
			cin >> x;
			countNode = 0;
			bst.countSubTreeNode(bst.search(x));
			cout << countNode << "\n";
		}
	}
}