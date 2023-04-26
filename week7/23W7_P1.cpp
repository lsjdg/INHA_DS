#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
	Node* parent;
	vector<Node*>childList;
	int value;
	int depth;
	Node(Node* parent, int value, int depth)
	{
		this->parent = parent;
		this->value = value;
		this->depth = depth;
	}
};
class Tree
{
public:
	Node* root;
	vector<Node*>nodeList;
	Tree()
	{
		root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* find(int x)
	{
		for (auto n : nodeList)
		{
			if (n->value == x)
				return n;
		}
		return nullptr;
	}
	void insert(int par, int chi)
	{
		Node* parentNode = find(par);
		if (parentNode == nullptr || find(chi) != nullptr)
			return;
		Node* newNode = new Node(parentNode, chi, parentNode->depth + 1);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void preOrder(Node* n)
	{
		if (n->childList.size() == 0)
			cout << n->depth << ' ';
		else
			cout << n->childList.size() << ' ';
		for (auto n : n->childList)
		{
			preOrder(n);
		}
	}
};

int main()
{
	int nodes, test;
	cin >> test;
	while (test--)
	{
		cin >> nodes;
		Tree t = Tree();
		while(--nodes)
		{
			int par, chi;
			cin >> par >> chi;
			t.insert(par, chi);
		}
		t.preOrder(t.root);
		cout << '\n';
	}
}
