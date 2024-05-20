#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 500 + 4

using namespace std;

int n, Time[MAX_NUM], inDeg[MAX_NUM], ret[MAX_NUM];
vector<int> grap[MAX_NUM];
queue<int> q;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> Time[i];

		int temp;
		while (cin >> temp)
		{
			if (temp == -1) break;
			grap[temp].push_back(i);
			inDeg[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!inDeg[i]) q.push(i);

		ret[i] = Time[i];
	}

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		for (int next : grap[cur])
		{
			ret[next] = max(ret[next], ret[cur] + Time[next]);

			if (--inDeg[next] == 0) q.push(next);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ret[i] << "\n";
	}

	return 0;
}