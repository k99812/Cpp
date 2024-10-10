#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define MAX_NUM 1000 + 4
#define INF 1e9

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];
vector<pair<int, int>> cordi;
queue<pair<int, int>> q;

int bfs()
{
	for (int i = 0; i < cordi.size(); i++)
	{
		visited[cordi[i].first][cordi[i].second] = 1;
		q.push(cordi[i]);
	}

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == -1) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == -1) continue;
			if (!visited[i][j]) return ret = 0;

			ret = max(ret, visited[i][j]);
		}
	}

	return ret;
}

int main()
{
	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				cordi.push_back({ i, j });
			}
		}
	}

	int ret = bfs();;

	cout << --ret << "\n";

	return 0;
}