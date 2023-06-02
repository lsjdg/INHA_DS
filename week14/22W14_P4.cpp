#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[101];
bool visited[101];
int test, n, m, question, start, a, b, maxVal{ 0 };

int bfs(int start)
{
	queue <int> q;
	q.push(start);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (top > maxVal)
			maxVal = top;
		if (visited[top])
			continue;
		visited[top] = true;
		for (auto i : graph[top])
		{
			if (!visited[i])
				q.push(i);
		}
	}
	return maxVal;
}

int main()
{
	cin >> test;
	while (test--)
	{
		cin >> n >> m >> question;
		while (m--)
		{
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		while (question--)
		{
			cin >> start;
			cout << bfs(start) << '\n';
			maxVal = 0;
		}
		for (int i{ 0 }; i < 101; i++)
		{
			visited[i] = false;
			graph[i].clear();
		}
	}
}