#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, dp[54][54], visited[54][54];
char a[54][54];
string s;

int go(int y, int x)
{
	if (a[y][x] == 'H') return 0;
	if (x < 0 || y < 0 || y >= n || x >= m) return 0;

	if (visited[y][x])
	{
		cout << -1 << "\n";
		exit(0);
	}

	int& ret = dp[y][x];
	if (ret) return ret;

	visited[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i] * (int)(a[y][x] - '0'), nx = x + dx[i] * (int)(a[y][x] - '0');
		ret = max(go(ny, nx) + 1, ret);
	}
	visited[y][x] = 0;

	return ret;
}

int main()
{
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}

	cout << go(0, 0) << "\n";

	return 0;
}