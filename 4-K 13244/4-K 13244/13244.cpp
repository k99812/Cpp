#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int t, n, m, a, b, visited[1004];
vector<int> adj[1004];

void dfs(int num)
{
	visited[num] = 1;
	for (int next : adj[num])
	{
		if (visited[next]) continue;
		dfs(next);
	}
	return;
}

int main()
{
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		for (int k = 0; k < 1004; k++) adj[k].clear();
		fill(&visited[0], &visited[1003], 0);

		int cnt = 0;
		cin >> n >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int j = 1; j <= n; j++)
		{
			if (visited[j]) continue;
			cnt++;
			dfs(j);
		}
		if (m == (n - 1) && cnt == 1)
		{
			cout << "tree\n";
		}
		else
		{
			cout << "graph\n";
		}
	}

	return 0;
}