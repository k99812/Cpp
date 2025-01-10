#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, vector<int>& parent)
{
	queue<int> q;
	q.push(1);

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int next : graph[now])
		{
			if (parent[now] == next) continue;
			parent[next] = now;
			q.push(next);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> graph(n + 1);
	vector<int> parent(n + 1);

	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	bfs(graph, parent);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}