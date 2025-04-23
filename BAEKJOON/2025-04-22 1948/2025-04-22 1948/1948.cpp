#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, s, e;
vector<int> dist, degree, visited;
vector<vector<pair<int, int>>> graph, regrapah;

void topologi()
{
	queue<int> q;
	q.push(s);

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (const pair<int, int>& p : graph[now])
		{
			int next = p.first, cost = p.second;

			dist[next] = max(dist[next], dist[now] + cost);

			if (--degree[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int bfs()
{
	int cnt = 0;
	queue<int> q;
	q.push(e);
	visited[e] = true;

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (const pair<int, int>& p : regrapah[now])
		{
			int next = p.first, cost = p.second;

			if (dist[now] - cost != dist[next]) continue;
			cnt++;

			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}

	return cnt;
}

int main()
{
	cin >> n >> m;

	dist = degree = visited = vector<int>(n + 1);
	graph = regrapah = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		regrapah[to].push_back({ from, cost });
		degree[to]++;
	}

	cin >> s >> e;

	topologi();
	int cnt = bfs();

	cout << dist[e] << "\n" << cnt << "\n";

	return 0;
}