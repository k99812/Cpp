#include<iostream>
#include<algorithm>

#define MAX_NUM 50 + 4

using namespace std;

struct Info
{
	int y,
		x,
		dir;
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM], ret;
Info info;

bool bIsDirty(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1) continue;
		if (visited[ny][nx]) continue;
		return true;
	}
	return false;
}

void go(int y, int x, int d)
{
	if (!visited[y][x])
	{
		visited[y][x] = 1;
		ret++;
	}
	
	if (bIsDirty(y, x))
	{
		for (int i = 0; i < 4; i++)
		{
			int dir = (d - i + 3) % 4;
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1 || visited[ny][nx]) continue;
			go(ny, nx, dir);
			break;
		}
	}
	else
	{
		int dir = (d + 2) % 4;
		int ny = y + dy[dir], nx = x + dx[dir];
		if (a[ny][nx]) return;
		go(ny, nx, d);
	}
}

int main()
{
	cin >> n >> m;
	cin >> info.y >> info.x >> info.dir;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	visited[info.y][info.x] = 1;
	ret++;
	go(info.y, info.x, info.dir);

	cout << ret << "\n";

	return 0;
}