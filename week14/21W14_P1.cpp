#include <iostream>
#include <vector>
using namespace std;

int test, v, e, a, b;
vector <int> graph[101];
bool visited[101];

void dfs(int x)
{
	cout << x << " ";
	visited[x] = true;
	for (auto i : graph[x])
	{
		if (!visited[i])
			dfs(i);
	}
}

int main()
{
	cin >> test;
	while (test--)
	{
		cin >> v >> e;
		while (e--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1);
		cout << '\n';

		for (int i{ 0 }; i < 101; i++)
		{
			graph[i].clear();
			visited[i] = false;
		}
	}
}
