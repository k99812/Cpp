#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string s, ans;
int a_target = 0, b_target = 0, c_target = 0;
int dp[55][55][55][4][4];

bool dfs(int a, int b, int c, int prev1, int prev2)
{
	if (a == a_target && b == b_target && c == c_target)
	{
		cout << ans << "\n";

		exit(0);
	}

	int& ret = dp[a][b][c][prev1][prev2];
	if (ret != -1) return ret;

	ret = 0;

	if (a < a_target)
	{
		ans += "A";
		if (dfs(a + 1, b, c, 1, prev1)) return ret = 1;
		ans.pop_back();
	}

	if (b < b_target && prev1 != 2)
	{
		ans += "B";
		if (dfs(a, b + 1, c, 2, prev1)) return ret = 1;
		ans.pop_back();
	}

	if (c < c_target && prev1 != 3 && prev2 != 3)
	{
		ans += "C";
		if (dfs(a, b, c + 1, 3, prev1)) return ret = 1;
		ans.pop_back();
	}

	return ret;
}

int main()
{
	cin >> s;

	for (const char c : s)
	{
		if (c == 'A') a_target++;
		else if (c == 'B') b_target++;
		else if (c == 'C') c_target++;
	}

	memset(dp, -1, sizeof(dp));

	dfs(0, 0, 0, 0, 0);

	cout << -1 << "\n";

	return 0;
} 