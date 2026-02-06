#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> matchA, matchB, visited, visitedA, visitedB;

bool dfs(int now)
{
	for (const int next : graph[now])
	{
		if (visited[next]) continue;

		visited[next] = true;

		if (matchB[next] == -1 || dfs(matchB[next]))
		{
			matchB[next] = now;
			return true;
		}
	}

	return false;
}

void cover_dfs(int a)
{
	visitedA[a] = true;

	for (const int b : graph[a])
	{
		if (b == matchA[a]) continue;
		if (visitedB[b]) continue;

		visitedB[b] = true;

		int nextA = matchB[b];
		if (nextA != -1 && !visitedA[nextA])
		{
			cover_dfs(nextA);
		}
	}
}

int main()
{
	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	matchA.assign(n + 1, -1);
	matchB.assign(m + 1, -1);

	for (int i = 1; i <= n; i++)
	{
		int e;
		cin >> e;
		for (int j = 1; j <= e; j++)
		{
			int to;
			cin >> to;
			graph[i].push_back(to);
		}
	}

	int match_num = 0;
	for (int i = 1; i <= n; i++)
	{
		visited.assign(m + 1, 0);

		if (dfs(i)) match_num++;
	}

	for (int i = 1; i <= m; i++) 
	{
		if (matchB[i] != -1)
		{
			matchA[matchB[i]] = i;
		}
	}

	visitedA.assign(n + 1, false);
	visitedB.assign(m + 1, false);

	for (int i = 1; i <= n; i++) 
	{
		if (matchA[i] == -1) 
		{
			cover_dfs(i);
		}
	}

	vector<int> retA, retB;

	for (int i = 1; i <= n; i++) 
	{
		if (!visitedA[i]) retA.push_back(i);
	}

	for (int i = 1; i <= m; i++)
	{
		if (visitedB[i]) retB.push_back(i);
	}

	cout << match_num << "\n";

	cout << retA.size() << " ";
	for (int x : retA) cout << x << " ";
	cout << "\n";

	cout << retB.size() << " ";
	for (int x : retB) cout << x << " ";
	cout << "\n";

	return 0;
}