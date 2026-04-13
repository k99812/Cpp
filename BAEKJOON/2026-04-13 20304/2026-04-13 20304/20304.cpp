#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const int INF = 1e9;

int n, m, n_size;
vector<int> pass, dist;

int bfs()
{
	queue<int> q;

	for (const int p : pass)
	{
		dist[p] = 0;
		q.push(p);
	}

	int ret = 0;
	while (q.size())
	{
		int now = q.front();
		q.pop();

		ret = max(ret, dist[now]);
		
		for (int i = 0; i <= n_size; i++)
		{
			int next = now ^ (1 << i);

			if (next <= n && dist[next] == -1)
			{
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m;

	n_size = log2(n) + 1;
	pass.assign(m, 0);
	dist.assign(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		cin >> pass[i];
	}

	cout << bfs() << "\n";

	return 0;
}