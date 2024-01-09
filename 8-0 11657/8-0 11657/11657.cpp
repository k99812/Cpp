#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

typedef long long ll;

const ll INF = 1e16;
ll n, m, A, B, C, dist[504];
vector<pair<int, int>> grap[504];
queue<int> q;

int main()
{
	cin >> n >> m;

	fill(&dist[0], &dist[504], INF);

	for (int i = 0; i < m; i++)
	{
		cin >> A >> B >> C;
		A--, B--;

		grap[A].push_back({ B, C });
	}

	dist[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int here = 0; here < n; here++)
		{
			for (pair<int, int> p : grap[here])
			{
				int there = p.first, d = p.second;

				if (dist[here] != INF && dist[there] > dist[here] + d)
				{
					if (i == n - 1) q.push(there);
					dist[there] = dist[here] + d;
				}
			}
		}
	}

	if (q.size()) cout << -1 << "\n";
	else for (int i = 1; i < n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";

	return 0;
}