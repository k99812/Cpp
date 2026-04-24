#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> match, visited;
vector<vector<int>> graph;

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

	match.assign(m + 1, -1);
	graph.assign(n + 1, vector<int>());

	for (int i = 1; i <= n; i++)
	{
		int op;
		cin >> op;
		for (int j = 0; j < op; j++)
		{
			int to;
			cin >> to;
			graph[i].push_back(to);
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			visited.assign(m + 1, 0);

			if (dfs(i))
			{
				ret++;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}