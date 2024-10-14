#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 100 + 4

using namespace std;

int n, m, visited[MAX_NUM], ret;
vector<int> grap[MAX_NUM];

void bfs()
{
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (q.size())
	{
		int here = q.front();
		q.pop();

		for (int next : grap[here])
		{
			if (visited[next])continue;
			visited[next] = visited[here] + 1;
			q.push(next);
		}
	}
}

int count()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) cnt++;
	}

	return cnt == 0 ? cnt : cnt - 1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		grap[from].push_back(to);
		grap[to].push_back(from);
	}

	bfs();

	cout << count() << "\n";

	return 0;
}