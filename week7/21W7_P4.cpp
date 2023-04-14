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
	Node(int value, int depth)
	{
		this->parent = nullptr;
		this->value = value;
		this->depth = depth;
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
		for (int i{ tmp }; i >= 0; i--)
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
		int idx = v->childList.size() - 1;
		for (int i{idx}; i>=0; i--)
			preOrder(v->childList[i]);
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
		Tree t;
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
		vector<Node*>tempList;
		for (int i{ 0 }; i < nodes; i++)
		{
			Node* newNode = new Node(valueArray[i], depthArray[i]);
			t.nodeList.push_back(newNode);
			if (depthArray[i] == 0)
			{
				t.root = newNode;
			}
			if (depthArray[i] < depthArray[i - 1])
			{
				while(tempList.size()!=0 && tempList.back()->depth > newNode->depth)
				{
					tempList.back()->parent = newNode;
					newNode->childList.push_back(tempList.back());
					tempList.pop_back();
				}
			}
			tempList.push_back(newNode);

		}
		t.preOrder(t.root);
		cout << '\n';
	}
}