#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int elem;
	Node* next;
	Node* prev;
public:
	Node()
	{
		this->elem = 0;
		this->next = nullptr;
		this->prev = nullptr;
	}
	~Node()
	{
		this->elem = 0;
		this->next = nullptr;
		this->prev = nullptr;
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
	~LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
		this->size = 0;
	}

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

	void reversePrint()
	{
		if (empty())
		{
			cout << "empty" << '\n';
			return;
		}

		Node* curNode = this->tail;
		while (curNode != nullptr)
		{
			cout << curNode->elem << " ";
			curNode = curNode->prev;
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
			appendNode->prev = tail;
			this->tail = appendNode;
		}

		this->size++;
		print();
	}

	

	int del(int index)
	{
		Node* deleteNode = new Node;
		int delNum;
		deleteNode = this->head;
		if (empty())
			return -1;
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
			Node* prevNode = this->head;
			for (int i{ 0 }; i < index; i++)
			{
				prevNode = deleteNode;
				deleteNode = deleteNode->next;
			}
			delNum = deleteNode->elem;
			prevNode->next = deleteNode->next;
			if (deleteNode == this->tail)
				this->tail = prevNode;
			else
				deleteNode->next->prev = prevNode;
			delete deleteNode;

			return delNum;
		}
		this->size--;
	}

	void max()
	{
		if (empty())
			cout << "empty" << '\n';
		else
		{
			int max = this->head->elem;
			Node* curPtr = this->head;
			for (int i{ 0 }; i < size; i++)
			{
				if (curPtr->elem >= max)
					max = curPtr->elem;
				curPtr = curPtr->next;
			}
			cout << max << '\n';
		}
	}
};