#include <iostream>
#include <vector>
using namespace std;

class pQueue
{
public:
	vector <int> v;
	bool empty() { return v.size() == 0; }
	void push(int e)
	{
		v.push_back(e);
	}
	bool isFive(int n)
	{
		return n % 5 == 0;
	}
	int pop()
	{
		vector<int>::iterator p = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		{
			if (!isFive(*p) && isFive(*i))
				p = i;
			else if (isFive(*p) == isFive(*i))
			{
				if (*p < *i)
					p = i;
			}
		}
		int maxPri = *p;
		v.erase(p);
		return maxPri;
	}
};

int main()
{
	int test, num, n;
	cin >> test;
	while (test--)
	{
		pQueue p;
		vector <int> v;
		cin >> num;
		for (int i{ 0 }; i < num; i++)
		{
			cin >> n;
			v.push_back(n);
		}
		for (int i{ 0 }; i < num; i++)
		{
			p.push(v.front());
			v.erase(v.begin());
		}
		for (int i{ 0 }; i < num; i++)
		{
			cout << p.pop() << ' ';
		}
		cout << '\n';

	}
}