#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MaxN = 20;
int r, c, map[MaxN + 4][MaxN + 4], visited[30], ret = -1;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
string s;

void dfs(int y, int x, int cnt)
{
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int next = (int)map[ny][nx] - 'A';
		if (visited[next]) continue;
		visited[next] = 1;
		dfs(ny, nx, cnt + 1);
		visited[next] = 0;
	}
	return;
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
		}
	}

	visited[(int)map[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	cout << ret << "\n";
	return 0;
}