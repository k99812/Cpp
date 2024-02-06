#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;

const int INF = 1e9;
int n, m, a, b, d, distFox[4004], distWolf[4004][2], ret;
vector<pair<int, int>> grap[4004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2;

void dijstraFox()
{
	fill(&distFox[0], &distFox[4004], INF);

	distFox[1] = 0;
	pq.push({ 0, 1 });

	while (pq.size())
	{
		int here = pq.top().second, here_dist = pq.top().first;
		pq.pop();

		if (distFox[here] != here_dist) continue;

		for (pair<int, int> n : grap[here])
		{
			int next = n.second, next_dist = n.first;

			if (distFox[next] > distFox[here] + next_dist)
			{
				distFox[next] = distFox[here] + next_dist;
				pq.push({ distFox[next], next });
			}
		}
	}
}

void dijstraWolf()
{
	fill(&distWolf[0][0], &distWolf[4003][1], INF);

	distWolf[1][0] = 0;
	pq2.push({ 0, 1, 0 });

	while (pq2.size())
	{
		int here_dist, here, cnt;
		tie(here_dist, here, cnt) = pq2.top(); pq2.pop();

		if (distWolf[here][cnt] != here_dist) continue;

		for (pair<int, int> n : grap[here])
		{
			int next = n.second, next_dist = !cnt ? n.first / 2 : n.first * 2;

			if (distWolf[next][!cnt] > distWolf[here][cnt] + next_dist)
			{
				distWolf[next][!cnt] = distWolf[here][cnt] + next_dist;
				pq2.push({ distWolf[next][!cnt], next, !cnt });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> d;

		grap[a].push_back({ d * 2, b });
		grap[b].push_back({ d * 2, a });
	}

	dijstraFox();
	dijstraWolf();

	for (int i = 2; i <= n; i++)
	{
		int wolf = min(distWolf[i][0], distWolf[i][1]);

		if (distFox[i] < wolf) ret++;
	}

	cout << ret << "\n";

	return 0;
}