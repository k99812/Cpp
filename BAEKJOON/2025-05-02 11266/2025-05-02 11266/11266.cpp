#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int v, e, cnt;
set<int> vertex;
vector<int> visited, parent;
vector<vector<int>> graph;

int dfs(int now, bool isRoot)
{
	visited[now] = ++cnt;
	int ret = visited[now];
	int child = 0;

	for (const int& next : graph[now])
	{
		if (parent[now] == next) continue;

		if (visited[next])
		{
			ret = min(ret, visited[next]);
			continue;
		}

		child++;
		parent[next] = now;
		int low = dfs(next, false);
		ret = min(ret, low);

		if (!isRoot && low >= visited[now])
		{
			vertex.insert(now);
		}
	}

	if (isRoot && child >= 2) 
	{
		vertex.insert(now);
	}

	return ret;
}

int main()
{
	cin >> v >> e;

	visited = parent = vector<int>(v + 1);
	graph = vector<vector<int>>(v + 1);

	for (int i = 0; i < e; i++)
	{
		int from, to;
		cin >> from >> to;

		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= v; i++)
	{
		if (!visited[i])
		{
			dfs(i, true);
		}
	}

	cout << vertex.size() << "\n";

	for (const int& i : vertex)
	{
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}