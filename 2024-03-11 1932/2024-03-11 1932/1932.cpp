#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, temp, dp[504][504];
vector<vector<int>> grap(504);

int go(int idx, int pos)
{
	if (idx == n)
	{
		return 0;
	}

	int& ret = dp[idx][pos];
	if (ret) return ret;

	if (idx == 0)
	{
		ret = max(ret, go(idx + 1, pos) + grap[idx][pos]);
	}
	else
	{
		ret = max(go(idx + 1, pos) + grap[idx][pos], go(idx + 1, pos + 1) + grap[idx][pos + 1]);
	}

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> temp;

			grap[i].push_back(temp);
		}
	}

	cout << go(0, 0) << "\n";

	return 0;
}