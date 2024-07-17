#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 400 + 4
#define INF 1e9

using namespace std;

int v, e, dist[MAX_NUM][MAX_NUM], ret = INF;

int main()
{
	cin >> v >> e;
	fill(&dist[0][0], &dist[MAX_NUM - 1][MAX_NUM], INF);

	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		
		dist[a][b] = c;
	}

	for (int k = 1; k <= v; k++)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j) continue;
			ret = min(ret, dist[i][j] + dist[j][i]);
		}
	}

	cout << (ret == INF ? -1 : ret) << "\n";

	return 0;
}