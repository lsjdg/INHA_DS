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
	void visit()
	{
		cout << depth << ' ';
	}
};

class Tree
{
public:
	Node* root;
	vector<Node*>nodeList;
	Tree()
	{
		this->root = new Node(nullptr, 1, 0);
		nodeList.push_back(root);
	}
	Node* find(int x)
	{
		for (auto node : nodeList)
		{
			if (node->value == x)
				return node;
		}
		return nullptr;
	}
	void insert(int par, int chi)
	{
		Node* parentNode = find(par);
		if (parentNode == nullptr)
			return;
		else
		{
			Node* childNode = new Node(parentNode, chi, parentNode->depth + 1);
			parentNode->childList.push_back(childNode);
			nodeList.push_back(childNode);
		}
	}
	void remove(int x)
	{
		Node* targetNode = find(x);
		if (targetNode == nullptr)
			return;
		else
		{
			Node* parentNode = targetNode->parent;
			for (auto node : targetNode->childList)
			{
				node->parent = parentNode;
				parentNode->childList.push_back(node);
			}
			for (int i{ 0 }; i < parentNode->childList.size(); i++)
			{
				if (parentNode->childList[i]->value == x)
					parentNode->childList.erase(parentNode->childList.begin() + i);
				break;
			}
			for (int i{ 0 }; i < nodeList.size(); i++)
			{
				if (nodeList[i]->value == x)
					nodeList.erase(nodeList.begin() + i);
				break;
			}
			delete targetNode;
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
};

int main()
{
	int test, nodes;
	cin >> test;
	while (test--)
	{
		Tree t = Tree();
		cin >> nodes;
		nodes--;
		while (nodes--)
		{
			int x, y;
			cin >> x >> y;
			t.insert(x, y);
		}
		t.postOrder(t.root);
		cout << '\n';
	}
}