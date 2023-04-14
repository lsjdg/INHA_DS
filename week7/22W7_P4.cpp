#include <iostream>
#include <vector>
using namespace std;

int capaList[10000] {0};
int capa;
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
	void postOrder(Node* v)
	{
		for (auto node : v->childList)
			postOrder(node);
		capa += capaList[v->value];
		
	}
	~Tree() {
		for (auto node : nodeList) {
			delete node;
		}
	}
};

int main()
{
	int nodes, test;
	Tree t = Tree();
	cin >> nodes >> test;
	for (int i{ 1 }; i < nodes; i++)
	{
		int x, y;
		cin >> x >> y;
		t.insert(x, y);
	}
	for (int i{ 0 }; i < nodes; i++)
	{
		int n, c;
		cin >> n >> c;
		capaList[n] = c;
	}
	while (test--)
	{
		capa = 0;
		int idx;
		cin >> idx;
		Node* targetNode = t.find(idx);
		t.postOrder(targetNode);
		cout << capa << '\n';
	}
}