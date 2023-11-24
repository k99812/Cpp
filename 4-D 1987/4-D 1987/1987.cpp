#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 24, MIN = - 1;
int n, m, ret = MIN;
char map[MAX][MAX];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
string s;

void dfs(int y, int x, int num, int cnt)
{
	ret = max(ret, cnt);
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		int next = 1 << (int)(map[ny][nx] - 'A');
		if ((num & next) == 0) dfs(ny, nx, num | next, cnt + 1);
	}
	return;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j];
		}
	}

	dfs(0, 0, 1 << (int)(map[0][0] - 'A'), 1);
	cout << ret << "\n";
	return 0;
}