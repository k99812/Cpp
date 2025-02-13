#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m;

void bfs(const int& num, const vector<vector<int>>& graph, vector<int>& visited)
{
	queue<int> q;
	q.push(num);
	visited[num] = true;

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int next : graph[now])
		{
			if (visited[next]) continue;

			visited[next] = true;
			q.push(next);
		}
	}
}

int main()
{
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);

	vector<int> visited(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		bfs(i, graph, visited);
		ret++;
	}

	cout << ret << "\n";

	return 0;
}