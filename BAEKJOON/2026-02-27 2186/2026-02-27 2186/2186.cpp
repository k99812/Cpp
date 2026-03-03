#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, k;
vector<string> arr;
vector<vector<vector<int>>> dp;
string target;

int dfs(int idx, int y, int x)
{
	if (idx == target.size() - 1) return 1;

	int& ret = dp[y][x][idx];
	if (ret != -1) return ret;

	ret = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			int ny = y + dy[i] * j, nx = x + dx[i] * j;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] != target[idx + 1]) continue;

			ret += dfs(idx + 1, ny, nx);
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m >> k;

	arr.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cin >> target;

	dp.assign(n, vector<vector<int>>(m, vector<int>(target.size(), -1)));

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == target[0])
			{
				ret += dfs(0, i, j);
			}
		}
	}

	cout << ret << "\n";

	return 0;
}