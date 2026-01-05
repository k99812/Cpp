#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int c, n, m;
vector<vector<int>> board, dp;

int count(int cur)
{
	int cnt = 0;
	for (int i = 1; i <= cur; i <<= 1)
	{
		if (cur & i) cnt++;
	}

	return cnt;
}

bool isSafeRow(int row, int cur)
{
	for (int j = 0; j < m; j++)
	{
		if ((cur & (1 << j)) == 0) continue;

		if (board[row][j] == 1) return false;

		if (j > 0 && (cur & (1 << (j - 1)))) return false;
	}

	return true;
}

bool isSafePrev(int cur, int prev)
{
	for (int j = 0; j < m; j++)
	{
		if((cur & (1 << j)) == 0) continue;

		if (j > 0 && prev & (1 << (j - 1))) return false;

		if (j < m - 1 && prev & (1 << (j + 1))) return false;
	}

	return true;
}

int go(int row, int prev)
{
	if (row == n) return 0;

	int& ret = dp[row][prev];
	if (ret != -1) return ret;

	ret = 0;

	for (int cur = 0; cur < (1 << m); cur++)
	{
		if (!isSafeRow(row, cur) || !isSafePrev(cur, prev)) continue;

		ret = max(ret, count(cur) + go(row + 1, cur));
	}

	return ret;
}

int main()
{
	cin >> c;

	while (c--)
	{
		cin >> n >> m;

		board = vector<vector<int>>(n, vector<int>(m));
		dp = vector<vector<int>>(n + 1, vector<int>(1 << m, -1));

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; j++)
			{
				board[i][j] = str[j] == '.' ? 0 : 1;
			}
		}

		cout << go(0, 0) << "\n";
	}

	return 0;
}