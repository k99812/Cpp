#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 50 + 4
#define INF 1e9

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM], ret = INF;
vector<pair<int, int>> v;
vector<int> num;

void bfs(queue<pair<int,int>>& q)
{
	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] != -1) continue;
			if (a[ny][nx] == 1) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				if (visited[i][j] == -1) return;
				else cnt = max(cnt, visited[i][j]);
			}
		}
	}

	ret = min(ret, cnt);
}

void go(int idx)
{
	if (num.size() == m)
	{
		fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], -1);
		queue<pair<int, int>> q;

		for (int i : num)
		{
			q.push({ v[i].first, v[i].second });
			visited[v[i].first][v[i].second] = 0;
			cout << i << " ";
		}
		cout << "\n";

		bfs(q);
		return;
	}

	for (int i = idx; i < v.size(); i++)
	{
		num.push_back(i);
		go(i + 1);
		num.pop_back();
	}

	return;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 2) v.push_back({ i, j });
		}
	}

	go(0);

	cout << (ret == INF ? -1 : ret) << "\n";

	return 0;
}