#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

class stringNode
{
private:
	Elem elem;
	stringNode* next;

	friend class stringLinkedList;
};

class stringLinkedList
{
private:
	stringNode* head;
	stringNode* tail;
public:
	stringLinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}
	~stringLinkedList() {}

	bool empty() const
	{
		if (this->head == NULL && this->tail == NULL)
			return true;
		return false;
	}

	Elem front() const
	{
		return head->elem;
	}
	void addFront(const Elem& e)
	{
		stringNode* v = new stringNode;
		if (empty())
		{
			tail = v;
		}

		v->elem = e;
		v->next = head;
		head = v;
	}

	void removeFront()
	{
		if (empty())
			return;

		stringNode* old = head;
		head = old->next;
		delete old;
		if (empty())
			tail = NULL;
	}
	void addBack(const Elem& e)
	{
		stringNode* v = new stringNode;
		v->elem = e;
		v->next = NULL;
		if (empty())
			head = tail = v;
	}
	void removeBack()
	{
		if (empty())
			return;

		stringNode* current = head;
		if (current = tail)
		{
			head = tail = NULL;
			delete current;
		}
		else
		{
			while (current->next != tail)
				current = current->next;
		}
		tail = current;
		delete current->next;
		tail->next = NULL;
	}
};