#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n;

int dijkstra(int start,vector<int>& dist, const vector<vector<pair<int, int>>>& graph)
{
	dist.resize(n + 1, INT32_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (pq.size())
	{
		int now = pq.top().second, now_dist = pq.top().first;
		pq.pop();

		if (dist[now] != now_dist) continue;

		for (pair<int, int> i : graph[now])
		{
			int next = i.second, next_dist = i.first;

			if (dist[next] > dist[now] + next_dist)
			{
				dist[next] = dist[now] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}

	int maxest = 0, num;
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] != INT32_MAX && dist[i] > maxest)
		{
			num = i;
			maxest = dist[i];
		}
	}

	return num;
}

int main()
{
	cin >> n;

	vector<int> dist(n + 1, INT32_MAX);
	vector<vector<pair<int, int>>> graph(n + 1);

	for (int i = 0; i < n; i++)
	{
		int from, to, dist;

		cin >> from;

		while (cin >> to)
		{
			if (to == -1) break;

			cin >> dist;

			graph[from].push_back({ dist, to });
		}
	}

	int num = dijkstra(1, dist, graph);

	cout << num << " : " << dist[num] << "\n";

	int ret = dijkstra(num, dist, graph);

	cout << ret << " : " << dist[ret] << "\n";

	return 0;
}