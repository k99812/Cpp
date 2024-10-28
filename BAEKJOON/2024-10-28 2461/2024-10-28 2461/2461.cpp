#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

int n, m, a[MAX_NUM][MAX_NUM], idx[MAX_NUM], ret = INF;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		sort(&a[i][0], &a[i][m]);

	}

	while (true)
	{
		int maxNum = 0;
		int minNum = INF;
		int minIdx = 0;

		for (int i = 0; i < n; i++)
		{
			if (minNum > a[i][idx[i]])
			{
				minNum = a[i][idx[i]];
				minIdx = i;
			}

			if (maxNum < a[i][idx[i]])
			{
				maxNum = a[i][idx[i]];
			}
		}

		ret = min(ret, maxNum - minNum);

		idx[minIdx]++; 

		if (idx[minIdx] == m) break;
	}

	cout << ret << "\n";

	return 0;
}