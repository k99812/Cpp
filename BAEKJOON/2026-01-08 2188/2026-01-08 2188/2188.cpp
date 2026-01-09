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

	graph = vector<vector<int>>(n + 1);
	match = vector<int>(m + 1, -1);

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int e;
			cin >> e;
			graph[i].push_back(e);
		}
	}

	int match_num = 0;
	for (int i = 1; i <= n; i++)
	{
		visited.assign(m + 1, false);

		if (dfs(i))
		{
			match_num++;
		}
	}

	cout << match_num << "\n";
	
	return 0;
}