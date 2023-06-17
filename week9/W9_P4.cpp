#include <iostream>
#include <vector>
using namespace std;

class Pqueue
{
public:
	vector <int> v;
	bool isEmpty() { return v.size() == 0; }
	void push(int e) { v.push_back(e); }
	bool isFive(int e) { return e % 5 == 0; }
	int pop()
	{
		vector <int>::iterator p = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		{
			if (*i % 5 != 0 && *p % 5 == 0)
				p = i;
			else if (isFive(*i) == isFive(*p))
			{
				if (*i < *p)
					p = i;
			}
		}
		int max = *p;
		v.erase(p);
		return max;
	}
};

int main()
{
	int test, elem, x;
	cin >> test;
	while (test--)
	{
		Pqueue pq;
		vector <int> seq;
		cin >> elem;
		for (int i{ 0 }; i < elem; i++)
		{
			cin >> x;
			pq.push(x);
		}
		while (!pq.isEmpty())
		{
			seq.push_back(pq.pop());
		}
		for (auto n : seq)
		{
			cout << n << ' ';
		}
		cout << '\n';
	}
}