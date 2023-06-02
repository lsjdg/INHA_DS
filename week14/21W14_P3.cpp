#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int test, v, e, a, b;
vector <int> graph[101];
bool visited[101];

void bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (visited[top])
			continue; 
		visited[top] = true;
		cout << top << " ";
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
		cin >> v >> e;
		while (e--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bfs();
		cout << '\n';

		for (int i{ 0 }; i < 101; i++)
		{
			graph[i].clear();
			visited[i] = false;
		}
	}
}
