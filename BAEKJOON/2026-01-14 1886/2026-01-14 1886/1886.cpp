#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<string> board;
vector<pair<int, int>> prisoner, door;
vector<vector<int>> dist, graph;
vector<int> match, visited;

void bfs(int idx)
{
	vector<vector<int>> v(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push(prisoner[idx]);
	v[prisoner[idx].first][prisoner[idx].second] = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (board[ny][nx] == 'X') continue;
			if (v[ny][nx] != -1) continue;

			v[ny][nx] = v[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	for (int i = 0; i < door.size(); i++)
	{
		int y = door[i].first, x = door[i].second;

		if (v[y][x] != -1)
		{
			dist[idx][i] = v[y][x];
		}
	}
}

bool dfs(int now)
{
	for (const int next : graph[now])
	{
		if (visited[next]) continue;

		visited[next] = true;

		if (match[next] == -1 || dfs(match[next]))
		{
			match[next] = now;
			return true;
		}
	}

	return false;
}

bool can_escape(int time)
{
	int p_cnt = prisoner.size(), d_cnt = door.size();

	graph = vector<vector<int>>(p_cnt, vector<int>());
	match = vector<int>(d_cnt * (time + 1), -1);

	for (int i = 0; i < p_cnt; i++)
	{
		for (int j = 0; j < d_cnt; j++)
		{
			int d = dist[i][j];
			if (d == INF) continue;

			for (int t = d; t <= time; t++)
			{
				int id = j * (time + 1) + t;
				graph[i].push_back(id);
			}
		}
	}

	int match_cnt = 0;
	for (int i = 0; i < p_cnt; i++)
	{
		visited.assign(d_cnt * (time + 1), false);

		if (dfs(i))
		{
			match_cnt++;
		}
	}

	return match_cnt == p_cnt;
}

int main()
{
	cin >> n >> m;

	board = vector<string>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 'D') door.push_back({ i, j });
			else if (board[i][j] == '.') prisoner.push_back({ i, j });
		}
	}

	if (prisoner.empty()) 
	{
		cout << 0 << "\n";
		return 0;
	}

	if (door.empty()) 
	{
		cout << "impossible" << "\n";
		return 0;
	}

	dist = vector<vector<int>>(prisoner.size(), vector<int>(door.size(), INF));
	for (int i = 0; i < prisoner.size(); i++)
	{
		bfs(i);
	}

	int low = 1, high = n * m * 2;
	int ret = -1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (can_escape(mid))
		{
			high = mid - 1;
			ret = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	if (ret == -1) cout << "impossible" << "\n";
	else cout << ret << "\n";

	return 0;
}