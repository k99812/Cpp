#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 32000 + 4

using namespace std;

int n, m, inDeg[MAX_NUM];
vector<int> grap[MAX_NUM];

void topology()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= n; i++)
	{
		if (!inDeg[i])
		{
			pq.push(i);
		}
	}

	while (pq.size())
	{
		int from = pq.top();
		cout << from << " ";
		pq.pop();

		for (int to : grap[from])
		{
			if (--inDeg[to] == 0)
			{
				pq.push(to);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		grap[a].push_back(b);
		inDeg[b]++;
	}

	topology();

	return 0;
}