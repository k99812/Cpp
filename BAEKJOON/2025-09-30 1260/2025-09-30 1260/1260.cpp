#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, start;
vector<vector<int>> graph;

void dfs(int now, vector<int>& visited, vector<int>& ret)
{
	visited[now] = true;
	ret.push_back(now);

	for (const int& next : graph[now])
	{
		if (visited[next]) continue;

		dfs(next, visited, ret);
	}

	return;
}

void bfs(vector<int>& visited, vector<int>& ret)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);
	ret.push_back(start);

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (const int& next : graph[now])
		{
			if (visited[next]) continue;

			q.push(next);
			visited[next] = true;
			ret.push_back(next);
		}
	}
}

void print(vector<int>& ret)
{
	for (const int& i : ret)
	{
		cout << i << " ";
	}
	cout << "\n";
}

int main()
{
	cin >> n >> m >> start;

	graph = vector<vector<int>>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	vector<int> ret, visited(n + 1);

	dfs(start, visited, ret);
	print(ret);

	ret.clear();
	visited.assign(n + 1, 0);

	bfs(visited, ret);
	print(ret);

	return 0;
}