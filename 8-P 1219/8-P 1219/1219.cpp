#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const long long INF = 1e18;
int n, m, s, d, vistied[104], x, y, z, isEnd;
long long cost[104], dist[104];
vector<pair<int, int>> grap[104];
queue<int> q;

int main()
{
	cin >> n >> s >> d >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> z;

		grap[x].push_back({ z, y });
	}

	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];     
	}

	fill(&dist[0], &dist[104], -INF);
	dist[s] = cost[s];

	for (int i = 0; i < n; i++)
	{
		for (int here = 0; here < n; here++)
		{
			for (pair<int, int> p : grap[here])
			{
				int next_dist = p.first, next = p.second;

				if (dist[here] != -INF && dist[here] + cost[next] - next_dist > dist[next])
				{
					dist[next] = dist[here] + cost[next] - next_dist;
					if (i == n - 1) q.push(here);
				}
			}  
		}
	}

	while (q.size())
	{
		int here = q.front(); q.pop();

		for (pair<int, int> next : grap[here])
		{
			if (next.second == d)
			{
				isEnd = 1;
				break;
			}

			if (!vistied[next.second])
			{
				vistied[next.second] = 1;
				q.push(next.second);
			}
		}
		if (isEnd) break;
	}

	if (dist[d] == -INF) cout << "gg" << "\n";
	else if (isEnd) cout << "Gee" << "\n";
	else cout << dist[d] << "\n";

	return 0;
}