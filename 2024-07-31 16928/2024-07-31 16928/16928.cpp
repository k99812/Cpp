#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 102
#define INF 1e9

using namespace std;

int n, m, a[MAX_NUM], visited[MAX_NUM], ret = INF;

void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0, 1 });

	while (q.size())
	{
		int pos = q.front().second, cnt = q.front().first;
		q.pop();

		for (int i = 1; i <= 6; i++)
		{
			int next_pos = pos + i, next_cnt = cnt + 1;

			if (visited[next_pos]) continue;
			if (next_pos > 100) continue;

			if (next_pos == 100)
			{
				ret = min(ret, cnt);
				return;
			}
			if (a[next_pos])
			{
				next_pos = a[next_pos];
			}

			visited[next_pos] = true;
			q.push({ next_cnt, next_pos });
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n + m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x] = y;
	}

	bfs();

	cout << ret + 1 << "\n";

	return 0;
}