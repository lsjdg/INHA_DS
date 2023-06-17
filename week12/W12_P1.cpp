#include <iostream>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry
{
	int key;
	string value;
	int valid;

	Entry()
	{
		key = 0;
		value = "";
		valid = NOITEM;
	}
	Entry(int _key, string _value)
	{
		key = _key;
		value = _value;
		valid = ISITEM;
	}
};

class HashTable
{
private:
	Entry* hashTable;
	int cap;
public:
	HashTable(int cap)
	{
		this->cap = cap;
		hashTable = new Entry[cap];
	}
	int hashFunc(int key) { return key % cap; }
	void put(int key, string value)
	{
		int idx = hashFunc(key);
		int probing = 1;
		while (hashTable[idx].valid == ISITEM && probing <= cap)
		{
			idx = hashFunc(idx + 1);
			probing++;
		}
		if (probing > cap) return;
		cout << probing + idx << '\n';
		hashTable[idx] = Entry(key, value);
	}
	void erase(int key)
	{
		int idx = hashFunc(key);
		int probing = 1;
		while (hashTable[idx].valid != NOITEM && probing <= cap)
		{
			if (hashTable[idx].valid == ISITEM && hashTable[idx].key == key)
			{
				cout << hashTable[idx].value << '\n';
				hashTable[idx].valid = AVAILABLE;
				return;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		cout << "None\n";
	}
	void find(int key)
	{
		int idx = hashFunc(key);
		int probing = 1;
		while (hashTable[idx].valid != NOITEM && probing <= cap)
		{
			if (hashTable[idx].valid == ISITEM && hashTable[idx].key == key)
			{
				cout << hashTable[idx].value << '\n';
				return;
			}
			idx = hashFunc(idx + 1);
			probing++;
		}
		cout << "None\n";
	}
	void vacant()
	{
		int count{ 0 };
		for (int i{ 0 }; i < cap; i++)
		{
			if (hashTable[i].valid != ISITEM)
				count++;
		}
		cout << count << '\n';
	}
};
int main()
{
	int test, c, x;
	string s;
	cin >> test >> c;
	HashTable h = HashTable(c);
	while (test--)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "put")
		{
			cin >> x >> s;
			h.put(x, s);
		}
		else if (cmd == "erase")
		{
			cin >> x;
			h.erase(x);
		}
		else if (cmd == "find")
		{
			cin >> x;
			h.find(x);
		}
		else if (cmd == "vacant")
		{
			h.vacant();
		}
	}
}