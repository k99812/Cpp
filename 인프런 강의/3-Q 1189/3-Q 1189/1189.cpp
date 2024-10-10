#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10;
int r, c, k, visited[MAX][MAX], ret;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char map[MAX][MAX];
string s;

void dfs(int y, int x, int dist)
{
	if (dist > k) return;
	else if (dist == k && y == 0 && x == (c - 1))
	{
		ret++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (visited[ny][nx]) continue;
		if (map[ny][nx] == 'T') continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, dist + 1);
		visited[ny][nx] = 0;
	}
}

int main()
{
	cin >> r >> c >> k;

	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
		}
	}

	visited[r - 1][0] = 1;
	dfs(r - 1, 0, 1);

	cout << ret << "\n";
	return 0;
}