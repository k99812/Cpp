#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n, m, k;
vector<int> candy, dp, parent;

int getParent(int num)
{
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b)
{
	int rootA = getParent(a), rootB = getParent(b);

	if (rootA != rootB)
	{
		if (rootB < rootA)
		{
			parent[rootA] = parent[rootB];
		}
		else
		{
			parent[rootB] = parent[rootA];
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	candy = vector<int>(n + 1);
	dp = vector<int>(n + 1);
	parent = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> candy[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		unionParent(a, b);
	}

	unordered_map<int, pair<int, int>> map;
	for (int i = 1; i <= n; i++)
	{
		int root = getParent(i);
		map[root].first++;
		map[root].second += candy[i];
	}

	vector<pair<int, int>> group;
	for (const auto& v : map)
	{
		group.push_back(v.second);
	}

	for (const pair<int, int>& itr : group)
	{
		for (int i = k - 1; i >= itr.first; i--)
		{
			dp[i] = max(dp[i], dp[i - itr.first] + itr.second);
		}
	}

	cout << dp[k - 1] << "\n";

	return 0;
}