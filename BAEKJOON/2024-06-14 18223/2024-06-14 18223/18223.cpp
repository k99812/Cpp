#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 5000 + 4
#define INF 1e9

using namespace std;

int v, e, p, dist[MAX_NUM];
vector<pair<int, int>> grap[MAX_NUM];

int dikjstra(int start, int des)
{
	fill(&dist[0], &dist[MAX_NUM], INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[start] = 0;
	pq.push({ 0, start });

	while (pq.size())
	{
		int here_dist = pq.top().first, here = pq.top().second;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pair<int, int> n : grap[here])
		{
			int next_dist = n.first, next = n.second;

			if (dist[next] > dist[here] + next_dist)
			{
				dist[next] = dist[here] + next_dist;
				pq.push({ dist[next], next });
			}
		}
	}

	return dist[des];
}

int main()
{
	cin >> v >> e >> p;

	for (int i = 0; i < e; i++)
	{
		int s, d, v;
		cin >> s >> d >> v;
		grap[s].push_back({ v, d });
		grap[d].push_back({ v, s });
	}

	if (dikjstra(1, v) == dikjstra(1, p) + dikjstra(p, v)) cout << "SAVE HIM\n";
	else cout << "GOOD BYE\n";

	return 0;
}