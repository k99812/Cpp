#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 10000 + 4

using namespace std;

int n, times[MAX_NUM], inDeg[MAX_NUM], dp[MAX_NUM], ret;
vector<int> grap[MAX_NUM];

void topology()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (inDeg[i] == 0)
		{
			q.push(i);
			dp[i] = times[i];
		}
	}

	while (q.size())
	{
		if (q.empty()) return;

		int from = q.front();
		ret = max(ret, dp[from]);
		q.pop();

		for (int next : grap[from])
		{
			dp[next] = max(dp[next], dp[from] + times[next]);

			if (--inDeg[next] == 0)
			{
				q.push(next);
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int m, t;
		cin >> t >> m;

		times[i] = t;
		inDeg[i] = m;

		for (int j = 1; j <= m; j++)
		{
			int pre;
			cin >> pre;

			grap[pre].push_back(i);
		}
	}

	topology();
	cout << ret << "\n";

	return 0;
}