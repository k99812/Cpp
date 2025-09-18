#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> dist, parent, vistied, cycle, inStack;

void dfs(int now)
{
	inStack[now] = true;
	vistied[now] = true;

	for (const int& next : graph[now])
	{
		if (parent[now] == next) continue;

		if (vistied[next])
		{
			if (inStack[next])
			{
				for (int cur = parent[now]; cur != next; cur = parent[cur])
				{
					cycle[cur] = true;
				}
				cycle[next] = true, cycle[now] = true;
			}
			continue;
		}

		parent[next] = now;
		dfs(next);
	}

	inStack[now] = false;
}

void bfs()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (cycle[i])
		{
			q.push(i);
			dist[i] = 1;
		}
	}

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (const int& next : graph[now])
		{
			if (dist[next]) continue;

			dist[next] = dist[now] + 1;
			q.push(next);
		}
	}
}

int main()
{
	cin >> n;
	graph = vector<vector<int>>(n + 1);
	dist = parent = vistied = cycle = inStack = vector<int>(n + 1);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);
	bfs();

	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] - 1 << " ";
	}

	return 0;
}