#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 500 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, a[MAX_NUM][MAX_NUM], dp[MAX_NUM][MAX_NUM], num;

int go(int y, int x)
{
	int& ret = dp[y][x];
	if (ret) return ret;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (y < 0 || x < 0 || y >= n || x >= n) continue;
		if (a[y][x] >= a[ny][nx]) continue;

		ret = max(ret, go(ny, nx) + 1);
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			num = max(num, go(i, j));
		}
	}

	cout << num + 1 << "\n";

	return 0;
}
