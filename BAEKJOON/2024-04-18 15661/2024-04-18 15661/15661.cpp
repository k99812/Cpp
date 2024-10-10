#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 20 + 4
#define INF 1e9

using namespace std;

int n, a[MAX_NUM][MAX_NUM], ret = INF, visited[MAX_NUM];

void combi(int idx, int cnt)
{
	if (cnt > n / 2)
	{
		return;
	}
	if (cnt > 0)
	{
		int startTeam = 0, linkTeam = 0;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (visited[i] && visited[j]) 
				{
					startTeam += a[i][j] + a[j][i];
				}
				else if (!visited[i] && !visited[j]) 
				{
					linkTeam += a[i][j] + a[j][i];
				}
			}
		}

		ret = min(ret, abs(startTeam - linkTeam));
	}

	for (int i = idx + 1; i < n; i++)
	{
		visited[i] = 1;
		combi(i , cnt + 1);
		visited[i] = 0;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	combi(-1, 0);

	cout << ret << "\n";

	return 0;
}