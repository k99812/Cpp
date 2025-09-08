#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
vector<vector<int>> graph;
vector<int> subtree;
ll ret;

int dfs(int now, int parent)
{
	subtree[now] = 1;

	for (const int& next : graph[now])
	{
		if (next == parent) continue;
		
		int cnt = dfs(next, now);
		ll out = n - cnt;
		ret += (ll)n * (n - 1) / 2 - out * (out - 1) / 2;
		subtree[now] += cnt;
	}

	return subtree[now];
}

int main()
{
	cin >> n;

	graph = vector<vector<int>>(n + 1);
	subtree = vector<int>(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);
	cout << ret << "\n";

	return 0;
}