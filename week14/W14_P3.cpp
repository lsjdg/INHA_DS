#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[1001];
bool visited[1001];
int test, n, m, a, b, c, target;
bool found{ false };

void bfs(int v)
{
	if (!found)
	{
		queue <int> q;
		q.push(v);
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			if (visited[top])
				continue;
			visited[top] = true;
			c++;
			if (top == target)
				cout << c << '\n';
			for (auto i : graph[top])
			{
				if (!visited[i])
				{
					q.push(i);
				}
			}
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
		bfs(start);
		for (int i{ 0 }; i < 1001; i++)
		{
			visited[i] = 0;
		}
	}
}