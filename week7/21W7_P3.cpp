#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node* parent;
	vector<Node*> childList;
	int depth;
	int value;

	Node(Node* parent, int value, int depth)
	{
		this->parent = parent;
		this->depth = depth;
		this->value = value;
	}
	void visit()
	{
		if (value == 1)
			cout << 0 << ' ';
		else
			cout << this->parent->value << ' ';
	}
	bool isLeaf()
	{
		if (this->childList.size() == 0)
			return true;
		return false;
	}
};
class Tree
{
public:
	Node* root;
	vector <Node*> nodeList;

	Tree()
	{
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* find(int x)
	{
		for (int i{ 0 }; i < nodeList.size(); i++)
		{
			if (x == nodeList[i]->value)
				return nodeList[i];
		}
		return nullptr;
	}
	void insert(int x, int y)
	{
		Node* parentNode = find(x);
		if (parentNode == nullptr)
			return;
		else
		{
			Node* insertNode = new Node(parentNode, y, parentNode->depth + 1);
			parentNode->childList.push_back(insertNode);
			nodeList.push_back(insertNode);
		}
	}
	void remove(int x)
	{
		Node* deleteNode = find(x);
		if (deleteNode == nullptr)
			return;
		else
		{
			for (auto n : deleteNode->childList)
			{
				deleteNode->parent->childList.push_back(n);
				n->parent = deleteNode->parent;
			}
			for (int i{ 0 }; i < deleteNode->parent->childList.size(); i++)
			{
				if (deleteNode->parent->childList[i] == deleteNode)
				{
					deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
					break;
				}
			}
			for (int i{ 0 }; i < nodeList.size(); i++)
			{
				if (nodeList[i] == deleteNode)
				{
					nodeList.erase(nodeList.begin() + i);
					break;
				}
			}
			delete deleteNode;
		}
	}
	void print(int x)
	{
		Node* parentNode = find(x);
		if (parentNode == nullptr || parentNode->childList.size() == 0)
		{
			cout << "0\n";
		}
		else
		{
			for (auto n : parentNode->childList)
			{
				cout << n->value << ' ';
			}
			cout << '\n';
		}
	}
	void preOrder(Node* v)
	{
		v->visit();
		for (auto node : v->childList)
			preOrder(node);
	}
	void postOrder(Node* v)
	{
		for (auto node : v->childList)
			postOrder(node);
		v->visit();
	}
	~Tree() {
		for (auto node : nodeList) {
			delete node;
		}
	}
};

int main()
{
	int test, nodes;
	cin >> test;
	while (test--)
	{
		Tree t = Tree();
		cin >> nodes;
		while (nodes--)
		{
			int par, chi;
			cin >> par >> chi;
			t.insert(par, chi);
		}

		t.postOrder(t.root);
		cout << '\n';
	}
}