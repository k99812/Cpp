#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 1e9

using namespace std;

int n, ret, max_node, max_num = -1;

void dijkstra(int idx, const vector<vector<pair<int, int>>>& grap, vector<int>& dist)
{
	fill(dist.begin(), dist.end(), INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[idx] = 0;
	pq.push({ 0, idx });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (const pair<int, int>& nx : grap[here])
		{
			int next = nx.second, next_dist = nx.first;

			if (dist[next] > dist[here] + next_dist)
			{
				dist[next] = dist[here] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}
}

int main()
{
	cin >> n;
	vector<vector<pair<int, int>>> grap(n + 1);
	vector<int> dist(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int from, to, wegiht;
		cin >> from >> to >> wegiht;

		grap[from].push_back({ wegiht, to });
		grap[to].push_back({ wegiht, from });
	}

	dijkstra(1, grap, dist);
	for (int i = 1; i <= n; i++) 
	{
		if (max_num < dist[i]) 
		{
			max_num = dist[i];
			max_node = i;
		}
	}
	
	dijkstra(max_node, grap, dist);
	max_node = 0;

	for (int i = 1; i <= n; i++) 
	{
		if (max_num < dist[i])
		{
			max_num = dist[i];
			max_node = i;
		}
	}

	cout << max_num << "\n";

	return 0;
}