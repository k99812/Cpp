#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int T;
string a_str, b_str, target;
vector<vector<int>> dp;

int dfs(int a, int b)
{
	if (a == a_str.size() && b == b_str.size()) return 1;

	int& ret = dp[a][b];
	if (ret != -1) return ret;

	ret = 0;

	int target_idx = a + b;

	if (a < a_str.size() && a_str[a] == target[target_idx])
	{
		if (dfs(a + 1, b) == 1) return ret = 1;
	}

	if (b < b_str.size() && b_str[b] == target[target_idx])
	{
		if (dfs(a, b + 1) == 1) return ret = 1;
	}

	return ret;
}

int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cin >> a_str >> b_str >> target;

		dp.assign(a_str.size() + 1, vector<int>(b_str.size() + 1, -1));

		if (dfs(0, 0) == 1)
		{
			cout << "Data set " << t << ": yes\n";
		}
		else
		{
			cout << "Data set " << t << ": no\n";
		}
	}

	return 0;
}