#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

int n, m, k;
vector<int> candy, parent, dp;

int getParent(int num)
{
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);
}

void unionParent(int a, int b)
{
	int root_a = getParent(a), root_b = getParent(b);
	if (root_a != root_b)
	{
		if (root_b < root_a)
		{
			parent[root_a] = root_b;
		}
		else
		{
			parent[root_b] = root_a;
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	candy = vector<int>(n + 1);
	parent = vector<int>(n + 1);
	dp = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> candy[i];
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (getParent(a) != getParent(b))
		{
			unionParent(a, b);
		}
	}

	unordered_map<int, pair<int, int>> umap;
	for (int i = 1; i <= n; i++)
	{
		int root = getParent(i);
		umap[root].first++;
		umap[root].second += candy[i];
	}

	vector<pair<int, int>> groups;
	for (const pair<int, pair<int, int>>& itr : umap)
	{
		groups.push_back(itr.second);
	}

	for (const pair<int, int>& itr : groups)
	{
		for (int i = k - 1; i >= itr.first; i--)
		{
			dp[i] = max(dp[i], dp[i - itr.first] + itr.second);
		}
	}
	
	cout << dp[k - 1] << "\n";

	return 0;
}