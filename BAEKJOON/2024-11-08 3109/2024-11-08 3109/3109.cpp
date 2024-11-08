#include<iostream>
#include<algorithm>
#include<string>

#define MAX_N 10000 + 4
#define MAX_M 500 + 4

using namespace std;

const int dy[] = { -1, 0, 1 };
const int dx[] = { 1, 1, 1 };
int n, m, vistied[MAX_N][MAX_M], ret;
char a[MAX_N][MAX_M];

bool dfs(int y, int x)
{
	vistied[y][x] = true;

	if (x == m - 1)
	{
		ret++;
		return true;
	}

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m || vistied[ny][nx]) continue;
		if (a[ny][nx] == 'x') continue;
		if (dfs(ny, nx)) return true;
	}

	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (vistied[i][0]) continue;
		dfs(i, 0);
	}

	cout << ret << "\n";

	return 0;
}