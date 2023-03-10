#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int elem;
	Node* next;
public:
	Node()
	{
		this->elem = 0;
		this->next = 0;
	}
	friend class LinkedList;
};

class LinkedList
{
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
	~LinkedList() {}

	bool empty() const
	{
		if (size == 0)
			return true;
		return false;
	}

	void print()
	{
		if (empty())
		{
			cout << "empty" << '\n';
			return;
		}

		Node* currPtr = this->head;
		while (currPtr != NULL)
		{
			cout << currPtr->elem << " ";
			currPtr = currPtr->next;
		}
		cout << '\n';
	}

	void addFront(int x)
	{
		Node* addNode = new Node;
		addNode->elem = x;

		if (empty())
		{
			this->head = addNode;
			this->tail = addNode;
		}

		else
		{
			addNode->next = head;
			head = addNode;
		}

		this->size++;
	}

	void removeFront()
	{
		Node* deleteNode = new Node;
		int delNum;
		deleteNode = this->head;
		if (size == 1)
		{
			delNum = this->head->elem;
			this->head = nullptr;
			this->tail = nullptr;
			cout << delNum << '\n';
			this->size--;
		}
		else
		{
			delNum = this->head->elem;
			head = deleteNode->next;
			delete deleteNode;
			cout << delNum << '\n';
			this->size--;
		}
		
	}

	void update(int index, int x)
	{
		if (index >= size)
			cout << "error" << '\n';
		else
		{
			Node* updateNode = this->head;
			for (int i{ 0 }; i < index; i++)
			{
				updateNode = updateNode->next;
			}
			updateNode->elem = x;
		}
	}

	void min()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			int min = this->head->elem;
			int minIndex{ 0 };
			Node* curPtr = this->head;
			for (int i{ 0 }; i < size; i++)
			{
				if (curPtr->elem < min)
				{
					min = curPtr->elem;
					minIndex = i;
				}
				curPtr = curPtr->next;
			}
			cout << minIndex << " " << min << '\n';
		}
	}
};

int main()
{
	int n;
	cin >> n;
	LinkedList l;
	for (int i{ 0 }; i < n; i++)
	{
		string s;
		cin >> s;
		
		if (s == "Print")
		{
			l.print();
		}
		if (s == "AddFront")
		{
			int x;
			cin >> x;
			l.addFront(x);
		}
		if (s == "RemoveFront")
		{
			l.removeFront();
		}
		if (s == "Update")
		{
			int index, x;
			cin >> index >> x;
			l.update(index, x);
		}
		if (s == "Min")
		{
			l.min();
		}
	}
}