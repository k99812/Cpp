#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 1e9;

int n, m;
vector<vector<int>> board;
pair<int, int> a1, a2, b1, b2;

int bfs(pair<int, int> start, pair<int, int> end)
{
	vector<vector<int>> visited(n + 1, vector<int>(m + 1, -1));
	vector<vector<pair<int, int>>> parent(n + 1, vector<pair<int, int>>(m + 1, { -1, -1 }));
	
	queue<pair<int, int>> q;
	q.push(start);
	visited[start.first][start.second] = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		if (end.first == y && end.second == x) break;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny > n || nx > m) continue;
			if (visited[ny][nx] != -1 || board[ny][nx] == 1) continue;

			visited[ny][nx] = visited[y][x] + 1;
			parent[ny][nx] = { y, x };
			q.push({ ny, nx });
		}
	}

	if (visited[end.first][end.second] == -1) return INF;

	int y = end.first, x = end.second;
	while (!(y == start.first && x == start.second))
	{
		board[y][x] = 1;
		int ny = parent[y][x].first, nx = parent[y][x].second;
		y = ny, x = nx;
	}
	board[start.first][start.second] = 1;

	return visited[end.first][end.second];
}

int go(pair<int, int> p1_start, pair<int, int> p1_end, pair<int, int> p2_start, pair<int, int> p2_end)
{
	board.assign(n + 1, vector<int>(m + 1, 0));

	board[p2_start.first][p2_start.second] = 1;
	board[p2_end.first][p2_end.second] = 1;

	int dist1 = bfs(p1_start, p1_end);
	if (dist1 == INF) return INF;

	board[p2_start.first][p2_start.second] = 0;
	board[p2_end.first][p2_end.second] = 0;

	int dist2 = bfs(p2_start, p2_end);
	if (dist2 == INF) return INF;

	return dist1 + dist2;
}

int main()
{
	cin >> m >> n;

	cin >> a1.second >> a1.first >> a2.second >> a2.first ;
	cin >> b1.second >> b1.first >> b2.second >> b2.first ;

	int ret = min(go(a1, a2, b1, b2), go(b1, b2, a1, a2));

	if (ret >= INF) cout << "IMPOSSIBLE\n";
	else cout << ret << "\n";

	return 0;
}