#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 1e9;
int T, n, m, t, s, g, h, a, b, d, dist[2004];
vector<int> ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(vector<pair<int, int>>* grap)
{
	fill(&dist[0], &dist[2004], INF);

	dist[s] = 0;
	pq.push({ 0, s });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (dist[here] != here_dist) continue;

		for (pair<int, int> p : grap[here])
		{
			int next = p.second, next_dist = p.first;

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
	cin >> T;

	while (T--)
	{
		cin >> n >> m >> t >> s >> g >> h;

		vector<pair<int, int>> grap[2004];

		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> d;

			d *= 2;

			if (a == g && b == h)
			{
				d--;
			}
			else if (a == h && b == g)
			{
				d--;
			}

			grap[a].push_back({ d, b });
			grap[b].push_back({ d, a });
		}

		vector<int> candi(t + 1);

		for (int i = 0; i < t; i++)
		{
			cin >> candi[i];
		}
		
		sort(candi.begin(), candi.begin() + t);

		dijkstra(grap);

		for (int i = 0; i < t; i++)
		{
			if (dist[candi[i]] % 2 == 1)
			{
				cout << candi[i] << "\n";
			}
		}
	}

	return 0;
}