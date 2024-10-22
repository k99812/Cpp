#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 32000 +4 

using namespace std;

int n, m, inDeg[MAX_NUM];
vector<int> grap[MAX_NUM];

void topology()
{
	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		if (inDeg[i] == 0)
		{
			q.push(i);
		}
	}

	while (q.size())
	{
		if (q.empty()) return;

		int from = q.front();
		cout << from << " ";
		q.pop();

		for (int to : grap[from])
		{
			if (--inDeg[to] == 0)
			{
				q.push(to);
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		grap[from].push_back(to);
		inDeg[to]++;
	}

	topology();
}