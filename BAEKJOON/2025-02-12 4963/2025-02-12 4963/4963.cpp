#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, m;

void bfs(pair<int, int> pos, const vector<vector<int>>& graph, vector<vector<int>>& vistied)
{
	queue<pair<int, int>> q;
	q.push(pos);
	vistied[pos.first][pos.second] = true;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (vistied[ny][nx] || !graph[ny][nx]) continue;

			q.push({ ny, nx });
			vistied[ny][nx] = true;
		}
	}
}

int main()
{
	while (cin >> m >> n)
	{
		if (!n && !m) break;

		vector<vector<int>> graph(n);
		for (vector<int>& v : graph) v.resize(m);

		vector<vector<int>> vistied(n);
		for (vector<int>& v : vistied) v.resize(m);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> graph[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!graph[i][j]) continue;
				if (vistied[i][j]) continue;
				
				bfs({ i, j }, graph, vistied);
				++cnt;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}