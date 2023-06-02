#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int test, n, m, question;
vector<int> graph[101];
bool visited[101];

int bfs(int start)
{
	queue <int> q;
	q.push(start);
	int count{ 0 };
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (visited[top])
			continue;
		visited[top] = true;
		count++;
		for (auto i : graph[top])
		{
			if (!visited[i])
			{
				q.push(i);
			}
		}
	}
	return count;
}
int main()
{
	cin >> test;
	while (test--)
	{
		cin >> n >> m >> question;
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (question--)
		{
			int start;
			cin >> start;
			cout << bfs(start) << '\n';

			for (int i{ 0 }; i < 101; i++)
				visited[i] = false;
		}
		for (int i{ 0 }; i < 101; i++)
			graph[i].clear();
	}
}