#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, flag;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int now, int depth)
{
	if (depth == 4)
	{
		flag = true;
		return;
	}

	visited[now] = true;

	for (const int& next : graph[now])
	{
		if (visited[next]) continue;

		dfs(next, depth + 1);

		if (flag) return;
	}

	visited[now] = false;
}

int main()
{
	cin >> n >> m;

	graph = vector<vector<int>>(n);
	visited = vector<int>(n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i, 0);

		if (flag) break;
	}
	
	cout << (flag ? 1 : 0) << "\n";

	return 0;
}