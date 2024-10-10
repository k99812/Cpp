#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

#define MAX_N 4004
#define INF 1e9

using namespace std;

int n, m, a, b, d, ret, distFox[MAX_N], distWolf[2][MAX_N];
vector<pair<int, int>> grap[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2;

void dijkstraFox()
{
	fill(&distFox[0], &distFox[MAX_N], INF);

	distFox[1] = 0;
	pq.push({ 0, 1 });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (distFox[here] != here_dist) continue;

		for (pair<int, int> nx : grap[here])
		{
			int next = nx.second, next_dist = nx.first;

			if (distFox[next] > distFox[here] + next_dist)
			{
				distFox[next] = distFox[here] + next_dist;
				pq.push({ distFox[next], next });
			}
		}
	}
}

void dijkstraWolf()
{
	fill(&distWolf[0][0], &distWolf[1][MAX_N], INF);

	distWolf[0][1] = 0;
	pq2.push({ 0, 1, 0 });

	while (pq2.size())
	{
		int here, here_dist, cnt;
		tie(here_dist, here, cnt) = pq2.top();
		pq2.pop();

		if(distWolf[cnt][here] != here_dist) continue;

		for (pair<int, int> nx : grap[here])
		{
			int next = nx.second, next_dist = !cnt ? nx.first / 2 : nx.first * 2;

			if (distWolf[!cnt][next] > distWolf[cnt][here] + next_dist)
			{
				distWolf[!cnt][next] = distWolf[cnt][here] + next_dist;
				pq2.push({ distWolf[!cnt][next], next, !cnt });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> d;

		grap[a].push_back({ d * 2, b });
		grap[b].push_back({ d * 2, a });
	}

	dijkstraFox();
	dijkstraWolf();

	for (int i = 2; i <= n; i++)
	{
		int wolf = min(distWolf[0][i], distWolf[1][i]);

		if (distFox[i] < wolf)
		{
			ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}