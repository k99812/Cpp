#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct State
{
	int y, x, bit;
};

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, 1, 0, -1 };
 
int n, m;
pair<int, int> start;
vector<string> board;

int bfs()
{
	queue<State> q;
	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1 << 6, -1)));

	q.push({ start.first, start.second, 0 });
	dist[start.first][start.second][0] = 0;

	while (q.size())
	{
		auto [y, x, bit] = q.front();
		q.pop();

		if (board[y][x] == '1') return dist[y][x][bit];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (board[ny][nx] == '#') continue;
			if (isupper(board[ny][nx]) && !(bit & (1 << (board[ny][nx] - 'A')))) continue;

			int nbit = bit;
			if (islower(board[ny][nx]))
			{
				nbit |= (1 << (board[ny][nx] - 'a'));
			}

			if (dist[ny][nx][nbit] != -1) continue;

			dist[ny][nx][nbit] = dist[y][x][bit] + 1;
			q.push({ ny, nx, nbit });
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;
	
	board.assign(n, "");

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '0')
			{
				start = { i, j };
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}