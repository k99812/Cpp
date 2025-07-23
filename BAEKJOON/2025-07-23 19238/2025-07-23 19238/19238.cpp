#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

struct Info
{
	pair<int, int> pos;
	pair<int, int> des;

	bool operator<(const Info& info) const
	{
		return pos < info.pos;
	}
};

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const int INF = 1e9;

ll gas;
int n, m;
pair<int, int> taxi;
vector<vector<int>> board, dist;
vector<Info> passenger;

void bfs(int sy, int sx)
{
	dist = vector<vector<int>>(n, vector<int>(n, INF));
	queue<pair<int, int>> q;
	q.push({ sy, sx });
	dist[sy][sx] = 0;

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (board[ny][nx] == 1 || dist[ny][nx] != INF) continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny, nx });
		}
	}
}

bool go()
{
	for (int i = 0; i < m; i++)
	{
		bfs(taxi.first, taxi.second);

		Info target({ { INF, INF }, {-1, -1} });
		int targetPos = -1;

		for (int itr = 0; itr < passenger.size(); itr++)
		{
			if (passenger[itr].pos.first == -1) continue;
			if (target.pos.first == INF)
			{
				target = passenger[itr];
				targetPos = itr;
				continue;
			}

			int y = passenger[itr].pos.first, x = passenger[itr].pos.second;
			if (dist[y][x] == INF) return false;

			int ty = target.pos.first, tx = target.pos.second;
			if (dist[ty][tx] == dist[y][x])
			{
				if (passenger[itr] < target)
				{
					target = passenger[itr];
					targetPos = itr;
				}
			}
			else if (dist[ty][tx] > dist[y][x])
			{
				target = passenger[itr];
				targetPos = itr;
			}
		}

		int ty = target.pos.first, tx = target.pos.second;
		if (gas < dist[ty][tx]) return false;

		passenger[targetPos].pos = { -1, -1 };
		gas -= dist[ty][tx];

		bfs(ty, tx);

		int gy = target.des.first, gx = target.des.second;

		if (gas < dist[gy][gx]) return false;

		gas += dist[gy][gx];
		taxi = { gy, gx };
	}

	return true;
}

int main()
{
	cin >> n >> m >> gas;

	board = vector<vector<int>>(n, vector<int>(n));
	passenger = vector<Info>(m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cin >> taxi.first >> taxi.second;
	taxi.first--, taxi.second--;

	for (int i = 0; i < m; i++)
	{
		cin >> passenger[i].pos.first >> passenger[i].pos.second
			>> passenger[i].des.first >> passenger[i].des.second;

		passenger[i].pos.first--, passenger[i].pos.second--,
			passenger[i].des.first--, passenger[i].des.second--;
	}

	bool flag = go();
	
	flag ? cout << gas << "\n" : cout << -1 << "\n";

	return 0;
}