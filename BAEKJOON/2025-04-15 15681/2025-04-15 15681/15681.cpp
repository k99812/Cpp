#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, r, q;
vector<vector<int>> tree;
vector<int> visited, subtree_size;

int dfs(const int& node)
{
	visited[node] = true;
	subtree_size[node] = 1;

	for (const int& next : tree[node])
	{
		if (visited[next]) continue;

		subtree_size[node] += dfs(next);
	}

	return subtree_size[node];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> r >> q;

	tree = vector<vector<int>>(n + 1);
	visited = subtree_size = vector<int>(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;

		tree[from].push_back(to);
		tree[to].push_back(from);
	}

	dfs(r);

	while (q--)
	{
		int num;
		cin >> num;

		cout << subtree_size[num] << "\n";
	}

	return 0;
}