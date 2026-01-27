#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct Info
{
	int y, x, dir, cnt;

	bool operator>(const Info& other) const
	{
		return cnt > other.cnt;
	}
};

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n;
vector<string> board;
vector<pair<int, int>> doors, mirrors;

int dijkstra()
{
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));
	priority_queue<Info, vector<Info>, greater<Info>> pq;
	
	for (int i = 0; i < 4; i++)
	{
		pq.push({ doors[0].first, doors[0].second, i, 0 });
		dist[doors[0].first][doors[0].second][i] = 0;
	}

	while (pq.size())
	{
		int y = pq.top().y, x = pq.top().x, d = pq.top().dir, cnt = pq.top().cnt;
		pq.pop();

		if (y == doors[1].first && x == doors[1].second)
		{
			return cnt;
		}

		int ny = y + dy[d], nx = x + dx[d], nd = d;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n || board[ny][nx] == '*') continue;
		
		if (dist[ny][nx][nd] > dist[y][x][d])
		{
			dist[ny][nx][nd] = dist[y][x][d];
			pq.push({ ny, nx, nd, cnt });
		}

		if (board[ny][nx] == '!')
		{
			for (int i = 1; i <= 3; i += 2)
			{
				nd = (d + i) % 4;
				if (dist[ny][nx][nd] > cnt)
				{
					dist[ny][nx][nd] = cnt + 1;
					pq.push({ ny, nx, nd, cnt + 1 });
				}
			}
		}
	}

	return 0;
}

int main()
{
	cin >> n;

	board.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '#')
			{
				doors.push_back({ i, j });
			}
			else if (board[i][j] == '!')
			{
				mirrors.push_back({ i, j });
			}
		}
	}

	cout << dijkstra() << "\n";

	return 0;
}