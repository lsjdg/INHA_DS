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
		this->head = NULL;
		this->tail = NULL;
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

	void append(int x)
	{
		Node* appendNode = new Node;
		appendNode->elem = x;

		if (empty())
		{
			this->head = appendNode;
			this->tail = appendNode;
		}
			
		else
		{
			this->tail->next = appendNode;
			this->tail = appendNode;
		}

		this->size++;
		print();
	}

	void insert(int index, int x)
	{
		Node* insertNode = new Node;
		insertNode->elem = x;
		
		if (index >= size)
		{
			cout << "Index Error" << '\n';
			return;
		}

		else if (empty())
		{
			this->head = insertNode;
			this->tail = insertNode;
		}

		else if (index == 0)
		{
			insertNode->next = head;
			head = insertNode;
		}

		else if (index == size)
		{
			append(x);
		}

		else
		{
			Node* curNode = this->head;
			for (int i{ 1 }; i < index; i++)
			{
				curNode = curNode->next;
			}
			insertNode->next = curNode->next;
			curNode->next = insertNode;
		}
		this->size++;
		print();
	}

	int del(int index)
	{
		Node* deleteNode = new Node;
		int delNum;
		deleteNode = this->head;
		if (index >= this->size)
			return -1;
		if (index == 0)
		{
			if (size == 1)
			{
				delNum = this->head->elem;
				this->head = nullptr;
				this->tail = nullptr;

				return delNum;
			}

			else
			{
				delNum = this->head->elem;
				head = deleteNode->next;
				delete deleteNode;

				return delNum;
			}
		}

		else
		{
			Node* curNode = this->head;
			for (int i{ 0 }; i < index; i++)
			{
				deleteNode = deleteNode->next;
				curNode->next = deleteNode;
			}
			delNum = deleteNode->elem;
			curNode->next = deleteNode->next;
			delete deleteNode;

			return delNum;
		}
		print();
		this->size--;
	}

	void min()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			int min = this->head->elem;
			Node* curPtr = this->head;
			for (int i{ 0 }; i < size; i++)
			{
				if (curPtr->elem <= min)
					min = curPtr->elem;
				curPtr = curPtr->next;
			}
			cout << min << '\n';
		}
	}
};