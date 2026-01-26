#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct Info
{
	int y, x, d;
};

const int INF = 1e9;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n;
vector<string> board;
vector<pair<int, int>> doors, mirrors;

int bfs()
{
	int mirror_size = mirrors.size();
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(mirror_size, INF)));
	queue<Info> q;
	
	for (int i = 0; i < 4; i++)
	{
		q.push({ doors[0].first, doors[0].second, i });
		dist[doors[0].first][doors[0].second][i] = 0;
	}

	int ret = INF;
	while (q.size())
	{
		int y = q.front().y, x = q.front().x, d = q.front().d;
		q.pop();

		while (true)
		{
			int ny = y + dy[d], nx = x + dx[d], nd = d;

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
			if (board[ny][nx] == '*' || dist[ny][nx][nd] != INF) break;
			if (board[ny][nx] == '!' || board[ny][nx] == '#')
			{
				dist[ny][nx][nd] = dist[y][x][d];
				y = ny, x = nx;
				break;
			}

			dist[ny][nx][nd] = dist[y][x][d];
			y = ny, x = nx;
		}

		if (board[y][x] == '#')
		{
			ret = min(ret, dist[y][x][d]);
			continue;
		}
		else if (board[y][x] == '!')
		{
			int nd = (d + 1 + 4) % 4;
			dist[y][x][nd] = dist[y][x][d] + 1;
			q.push({ y, x, nd });

			nd = (d + 1 + 4) % 4;
			dist[y][x][nd] = dist[y][x][d] + 1;
			q.push({ y, x, nd });
		}
	}

	return ret;
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


	return 0;
}