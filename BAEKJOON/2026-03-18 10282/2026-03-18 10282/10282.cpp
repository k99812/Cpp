#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;

int t, n, d, c;
vector<vector<pair<int, int>>> graph;

pair<int, int> dijkstra(int start)
{
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.size())
	{
		int now = pq.top().second, now_dist = pq.top().first;
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (const pair<int, int> p : graph[now])
		{
			int next = p.first, next_dist = p.second;

			if (dist[next] > dist[now] + next_dist)
			{
				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}

	int cnt = 0, time = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != INF)
		{
			cnt++;
			time = max(time, dist[i]);
		}
	}

	return { cnt, time };
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n >> d >> c;

		graph.assign(n + 1, vector<pair<int, int>>());

		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a, s });
		}

		pair<int, int> ret = dijkstra(c);

		cout << ret.first << " " << ret.second << "\n";
	}

	return 0;
}