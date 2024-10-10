#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 2500 + 4
#define INF 1e9

using namespace std;

struct info
{
	int from,
		to,
		cost;
};

int t, n, m, w, dist[MAX_NUM];
vector<info> grap;

bool Bellman_Ford()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < grap.size(); j++)
		{
			int from = grap[j].from, to = grap[j].to, cost = grap[j].cost;

			if (dist[to] > dist[from] + cost)
			{
				dist[to] = dist[from] + cost;
			}
		}
	}

	for (int i = 0; i < grap.size(); i++)
	{
		int from = grap[i].from, to = grap[i].to, cost = grap[i].cost;

		if (dist[to] > dist[from] + cost)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> t;

	while (t--)
	{
		grap.clear();
		fill(&dist[0], &dist[MAX_NUM], INF);
		cin >> n >> m >> w;

		for (int i = 0; i < m; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			grap.push_back({ s, e, t });
			grap.push_back({ e, s, t });
		}

		for (int i = 0; i < w; i++)
		{
			int s, e, t;
			cin >> s >> e >> t;
			grap.push_back({ s, e, -t });
		}

		cout << (Bellman_Ford() ? "YES" : "NO") << "\n";
	}

	return 0;
}