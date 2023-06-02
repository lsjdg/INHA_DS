#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[101];
bool visited[101];
int test, n, m, a, b, c{0};

void dfs(int v)
{
	c++;
	if (c % 2 == 1)
		cout << v << " ";
	visited[v] = true;
	for (auto i : graph[v])
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
		cin >> n >> m;
		while (m--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dfs(1);
		c = 0;
		cout << '\n';
		for (int i{ 0 }; i < 101; i++)
		{
			visited[i] = 0;
			graph[i].clear();
		}
	}
}