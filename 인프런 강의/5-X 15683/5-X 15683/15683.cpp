#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e8;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[10][10], visited[10][10], ret = INF;
vector<pair<int, int>> cctv;

vector<pair<int, int>> watched(int idx, int dir)
{
	vector<pair<int, int>> temp;
	int y = cctv[idx].first;
	int x = cctv[idx].second;

	if (a[y][x] == 1)
	{
		while (true)
		{
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
			if (a[ny][nx] == 6) break;
			if (a[ny][nx] == 0)
			{
				a[ny][nx] = 9;
				temp.push_back({ ny, nx });
			}
			y = ny, x = nx;
		}
	}
	else if(a[y][x] == 2)
	{
		for (int i = 0; i <= 2; i += 2)
		{
			int ty = y;
			int tx = x;
			while (true)
			{
				int ny = ty + dy[(dir + i) % 4], nx = tx + dx[(dir + i) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (a[ny][nx] == 6) break;
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 9;
					temp.push_back({ ny, nx });
				}
				ty = ny, tx = nx;
			}
		}
	}
	else if (a[y][x] == 3)
	{
		for (int i = 0; i < 2; i++)
		{
			int ty = y;
			int tx = x;
			while (true)
			{
				int ny = ty + dy[(dir + i) % 4], nx = tx + dx[(dir + i) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (a[ny][nx] == 6) break;
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 9;
					temp.push_back({ ny, nx });
				}
				ty = ny, tx = nx;
			}
		}
	}
	else if (a[y][x] == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			int ty = y;
			int tx = x;
			while (true)
			{
				int ny = ty + dy[(dir + i) % 4], nx = tx + dx[(dir + i) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (a[ny][nx] == 6) break;
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 9;
					temp.push_back({ ny, nx });
				}
				ty = ny, tx = nx;
			}
		}
	}
	else if (a[y][x] == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			int ty = y;
			int tx = x;
			while (true)
			{
				int ny = ty + dy[(dir + i) % 4], nx = tx + dx[(dir + i) % 4];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
				if (a[ny][nx] == 6) break;
				if (a[ny][nx] == 0)
				{
					a[ny][nx] = 9;
					temp.push_back({ ny, nx });
				}
				ty = ny, tx = nx;
			}
		}
	}
	return temp;
}

void go(int idx)
{
	if (idx == cctv.size())
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 0) sum++;
			}
		}
		ret = min(ret, sum);
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		vector<pair<int, int>> temp = watched(idx, i);
		go(idx + 1);
		for (auto p : temp) a[p.first][p.second] = 0;
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] && a[i][j]  != 6) cctv.push_back({ i, j });
		}
	}
	go(0);
	cout << ret << "\n";

	return 0;
}