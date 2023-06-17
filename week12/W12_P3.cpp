#include <iostream>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry
{
	int key;
	int valid;
	string value;

	Entry()
	{
		key = 0;
		valid = NOITEM;
		value = "";
	}
	Entry(int _key, string _value)
	{
		key = _key;
		valid = ISITEM;
		value = _value;
	}
};

class HashTable
{
private:
	Entry* hashTable;
	int cap, divisor;
public:
	HashTable(int cap, int divisor)
	{
		hashTable = new Entry[cap];
		this->cap = cap;
		this->divisor = divisor;
	}
	int funcOne(int k) { return k % cap; }
	int funcTwo(int k) { return divisor - (k % divisor); }
	void put(int k, string s)
	{
		int idx = funcOne(k);
		int probing = 1;
		while (hashTable[idx].valid == ISITEM && probing <= cap)
		{
			idx = funcOne(idx + funcTwo(k));
			probing++;
		}
		if (probing > cap) return;
		hashTable[idx] = Entry(k, s);
		cout << idx + probing << '\n';
	}
	void erase(int k)
	{
		int idx = funcOne(k);
		int probing = 1;
		while (hashTable[idx].valid != NOITEM && probing <= cap)
		{
			if (hashTable[idx].key == k && hashTable[idx].valid == ISITEM)
			{
				cout << hashTable[idx].value << '\n';
				hashTable[idx].valid = AVAILABLE;
				return;
			}
			idx = funcOne(idx + funcTwo(k));
			probing++;
		}
		cout << "None\n";
	}
	void find(int k)
	{
		int idx = funcOne(k);
		int probing = 1;
		while (hashTable[idx].valid != NOITEM && probing <= cap)
		{
			if (hashTable[idx].key == k && hashTable[idx].valid == ISITEM)
			{
				cout << hashTable[idx].value << '\n';
				return;
			}
			idx = funcOne(idx + funcTwo(k));
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
	int test, cap, divisor;
	cin >> test >> cap >> divisor;
	HashTable ht = HashTable(cap, divisor);
	while (test--)
	{
		string s, val;
		int x;
		cin >> s;
		if (s == "put")
		{
			cin >> x >> val;
			ht.put(x, val);
		}
		else if (s == "find")
		{
			cin >> x;
			ht.find(x);
		}
		else if (s == "erase")
		{
			cin >> x;
			ht.erase(x);
		}
		else if (s == "vacant")
		{
			ht.vacant();
		}
	}

}