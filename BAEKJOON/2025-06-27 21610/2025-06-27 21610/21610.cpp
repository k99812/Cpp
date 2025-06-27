#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int n, m;
vector<vector<int>> graph;
vector<pair<int, int>> clouds;

void go(int d, int s)
{
	vector<vector<bool>> visited = vector<vector<bool>>(n, vector<bool>(n, false));
	vector<pair<int, int>> newClouds;

	for (const pair<int, int>& itr : clouds)
	{
		int ny = (itr.first + dy[d] * (s % n) + n) % n;
		int nx = (itr.second + dx[d] * (s % n) + n) % n;

		graph[ny][nx]++;
		visited[ny][nx] = true;
		newClouds.push_back({ ny, nx });
	}

	for (const pair<int, int>& itr : newClouds)
	{
		int y = itr.first;
		int x = itr.second;
		int cnt = 0;
		for (int dir = 1; dir < 8; dir += 2)
		{
			int ny = y + dy[dir], nx = x + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (graph[ny][nx]) ++cnt;
		}
		graph[y][x] += cnt;
	}

	clouds.clear();

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (!visited[y][x] && graph[y][x] >= 2)
			{
				graph[y][x] -= 2;
				clouds.push_back({ y, x });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	graph = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	clouds = { {n - 1, 0}, {n - 1, 1}, {n - 2, 0}, {n - 2, 1} };

	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
		go(--d, s);
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret += graph[i][j];
		}
	}
	cout << ret << "\n";

	return 0;
}