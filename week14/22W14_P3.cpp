#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[101];
bool visited[101];
int test, n, m, a, b;
int c{ 0 };

void bfs()
{
	queue <int> q;
	q.push(1);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (visited[top])
			continue;
		c++;
		if (c % 2 == 1)
			cout << top << " ";
		visited[top] = true;
		for (auto i : graph[top])
		{
			if (!visited[i])
				q.push(i);
		}
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
		bfs();
		cout << '\n';
		for (int i{ 0 }; i < 101; i++)
		{
			visited[i] = false;
			graph[i].clear();
		}
	}
}