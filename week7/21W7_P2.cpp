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
		cout << this->value << ' ';
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
	Node* findDepth(int d)
	{
		int tmp = (int)nodeList.size() - 1;
		for (int i{tmp}; i>=0; i--)
		{
			if (nodeList[i]->depth == d)
			{
				return nodeList[i];
				break;
			}
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
	int test;
	cin >> test;
	while (test--)
	{
		Tree t = Tree();
		int nodes;
		cin >> nodes;
		int* valueArray = new int[nodes];
		int* depthArray = new int[nodes];
		for (int i{ 0 }; i < nodes; i++)
		{
			cin >> valueArray[i];
		}
		for (int i{ 0 }; i < nodes; i++)
		{
			cin >> depthArray[i];
		}
		for (int i{ 1 }; i < nodes; i++)
		{
			if (depthArray[i] == 1)
			{
				t.insert(t.root->value, valueArray[i]);
			}
			else if (depthArray[i] > depthArray[i - 1])
			{
				t.insert(valueArray[i - 1], valueArray[i]);
			}
			else if (depthArray[i] == depthArray[i - 1])
			{
				Node* curNode = t.find(valueArray[i - 1]);
				t.insert(curNode->parent->value, valueArray[i]);
			}
			else if (depthArray[i] < depthArray[i - 1])
			{
				t.insert(t.findDepth(depthArray[i]-1)->value, valueArray[i]);
			}
		}
		t.postOrder(t.root);
	}
}