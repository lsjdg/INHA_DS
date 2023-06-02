#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int test, n, m, question;
vector<int> graph[101];
bool visited[101];

int bfs(int start, int end)
{
	queue< pair<int, int> > q;
	q.push({ start, 0 });
	while (!q.empty())
	{
		int value = q.front().first;
		int distance = q.front().second;
		q.pop();
		if (value == end)
			return distance;
		if (visited[value])
			continue;
		visited[value] = true;
		for (auto i : graph[value])
		{
			if (!visited[i])
				q.push({ i, distance + 1 });
		}
	}
	return 0;
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
			int start, end;
			cin >> start >> end;
			cout << bfs(start, end) << '\n';

			for (int i{ 0 }; i < 101; i++)
				visited[i] = false;
		}
		for (int i{ 0 }; i < 101; i++)
			graph[i].clear();
	}
}