#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> match, visited;

bool dfs(int now)
{
	for (const int next : graph[now])
	{
		if (visited[next]) continue;

		visited[next] = true;

		if (match[next] == -1 || dfs(match[next]))
		{
			match[next] = now;
			return true;
		}
	}

	return false;
}

int main()
{
	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	match.assign(n + 1, -1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	int match_cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		visited.assign(n + 1, 0);

		if (dfs(i))
		{
			match_cnt++;
		}
	}

	cout << match_cnt << "\n";

	return 0;
}