#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

const int MAX = 14, INF = 1e8;
int n, map[MAX][MAX], visited[MAX][MAX], ret = INF;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool check(int y, int x)
{
	if (visited[y][x]) return false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) return false;
		if (visited[ny][nx]) return false;
	}
	return true;
}

int SetFlower(int y, int x)
{
	visited[y][x] = 1;
	int t = map[y][x];
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		visited[ny][nx] = 1;
		t += map[ny][nx];
	}
	return t;
}

void ClearFlower(int y, int x)
{
	visited[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		visited[ny][nx] = 0;
	}
}

void go(int cnt, int sum)
{
	if (cnt == 3)
	{
		ret = min(ret, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (check(i, j))
			{
				go(cnt + 1, sum + SetFlower(i, j));
				ClearFlower(i, j);
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	go(0, 0);
	cout << ret << "\n";
	return 0;
}