#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

int n, m, a[MAX_NUM][MAX_NUM], idx[MAX_NUM], ret = INF, maxNum = -1;

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

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++)
	{
		sort(&a[i][0], &a[i][m]);
		maxNum = max(maxNum, a[i][0]);
		pq.push({ a[i][0], i });
	}

	cout << "\n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	while (pq.size())
	{
		int minNum = pq.top().first, classIdx = pq.top().second;
		pq.pop();

		ret = min(ret, maxNum - minNum);

		if (++idx[classIdx] == m) break;

		pq.push({ a[classIdx][idx[classIdx]], classIdx });

		maxNum = max(maxNum, a[classIdx][idx[classIdx]]);
	}

	cout << ret << "\n";

	return 0;
}