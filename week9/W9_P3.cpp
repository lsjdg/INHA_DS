#include <iostream>
#include <vector>
using namespace std;

class Pqueue
{
public:
	vector <int> v;
	bool isEmpty() { return v.size() == 0; }
	void push(int e) { v.push_back(e); }
	int pop()
	{
		vector<int>::iterator max = v.begin();
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
		{
			if (*i > *max)
				max = i;
		}
		int m = *max;
		v.erase(max);
		return m;
	}
};

int main()
{
	int test, elem, x;
	cin >> test;
	while (test--)
	{
		Pqueue pq;
		vector<int> seq;
		cin >> elem;
		for (int i{ 0 }; i < elem; i++)
		{
			cin >> x;
			pq.push(x);
		}
		vector <int> result;
		for (int i{ 0 }; i < elem; i++)
		{
			seq.push_back(pq.pop());
			if (i > 0)
			{
				result.push_back(seq.front() - seq.back());
			}
		}
		for (auto n : seq)
		{
			cout << n << ' ';
		}
		cout << '\n';
		for (auto n : result)
		{
			cout << n << ' ';
		}
		cout << '\n';
	}
}