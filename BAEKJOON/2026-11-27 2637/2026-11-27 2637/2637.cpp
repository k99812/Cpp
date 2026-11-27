#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m;
vector<int> inDegree, isBase;
vector<vector<int>> dp;
vector<vector<pair<int, int>>> graph;

void bfs()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (inDegree[i] == 0)
		{
			isBase[i] = true;
			dp[i][i] = 1;
			q.push(i);
		}
	}

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (const auto [next, cost] : graph[now])
		{
			for (int b = 1; b <= n; b++)
			{
				if (dp[now][b] > 0)
				{
					dp[next][b] += dp[now][b] * cost;
				}
			}

			if (--inDegree[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	graph.assign(n + 1, vector<pair<int, int>>());
	inDegree.assign(n + 1, 0);
	isBase.assign(n + 1, 0);
	dp.assign(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;

		inDegree[x]++;
		graph[y].push_back({ x, k });
	}

	bfs();

	for (int i = 1; i <= n; i++)
	{
		if (isBase[i])
		{
			cout << i << " " << dp[n][i] << "\n";
		}
	}

	return 0;
}