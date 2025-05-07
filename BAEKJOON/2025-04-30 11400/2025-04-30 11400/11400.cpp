#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int v, e, cnt;
vector<int> visited, parent, inStack;
vector<vector<int>> graph;
vector<pair<int, int>> bridge;

int dfs(int start)
{
	visited[start] = ++cnt;
	int ret = visited[start];
	inStack[start] = true;

	for (const int& next : graph[start])
	{
		if (parent[start] == next) continue;
		if (visited[next])
		{
			if (inStack[next])
			{
				cout << "사이클 노드 : ";
				for (int cur = start; cur != next; cur = parent[cur])
				{
					cout << cur << " ";
				}
				cout << next << "\n";
			}

			ret = min(ret, visited[next]);
			continue;
		}
		
		parent[next] = start;
		int low = dfs(next);
		ret = min(ret, low);

		if (low > visited[start])
		{
			bridge.push_back({ min(start, next), max(start, next) });
		}
	}
	inStack[start] = false;

	return ret;
}

int main()
{
	cin >> v >> e;

	visited = parent = inStack = vector<int>(v + 1);
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
			dfs(i);
		}
	}

	sort(bridge.begin(), bridge.end());

	cout << bridge.size() << "\n";
	for (const pair<int, int>& i : bridge)
	{
		cout << i.first << " " << i.second << "\n";
	}

	return 0;
}