#include<iostream>
#include<algorithm>
#include<vector>

#define INF 1e9

using namespace std;

const int dy[] = { 0, 1, 0 };
const int dx[] = { 1, 0, -1 };
int n, m, dp[1004][1004][3];

int dfs(int y, int x, int dir, const vector<vector<int>>& graph, vector<vector<int>>& visited)
{
	if (y == n - 1 && x == m - 1)
	{
		return graph[y][x];
	}

	int& ret = dp[y][x][dir];
	if (ret != -INF) return ret;

	for (int i = 0; i < 3; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx]) continue;

		visited[ny][nx] = true;
		ret = max(ret, dfs(ny, nx, i, graph, visited) + graph[y][x]);
		visited[ny][nx] = false;
	}

	return ret;
}

int main()
{
	cin >> n >> m;
	
	vector<vector<int>> graph(n);
	for (vector<int>& v : graph) v.resize(m);

	vector<vector<int>> visited(n);
	for (vector<int>& v : visited) v.resize(m);

	fill(&dp[0][0][0], &dp[1003][1003][3], -INF);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
		}
	}

	visited[0][0] = true;
	cout << dfs(0, 0, 0, graph, visited) << "\n";

	return 0;
}