#include <iostream>
#include <vector>
using namespace std;

vector <int> graph[1001];
bool visited[1001];
int test, n, m, a, b, c{0}, target;
bool found{ false };
void dfs(int v)
{
	if (!found)
	{
		if (visited[v]) return;
		c++;
		if (v == target)
		{
			cout << c << '\n';
			found = true;
			return;
		}
		visited[v] = true;
		for (auto i : graph[v])
		{
			if (!visited[i])
				dfs(i);
		}
	}
}

int main()
{
	cin >> n >> m >> test;
	while (m--)
	{
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	while (test--)
	{
		int start;
		cin >> start >> target;
		c = 0;
		found = false;
		dfs(start);
		for (int i{ 0 }; i < 1001; i++)
		{
			visited[i] = 0;
		}
	}
}