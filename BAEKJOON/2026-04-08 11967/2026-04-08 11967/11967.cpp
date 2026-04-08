#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<bool>> visited, light;
vector<vector<vector<pair<int, int>>>> board;

int bfs()
{
	visited.assign(n + 1, vector<bool>(n + 1, false));
	light.assign(n + 1, vector<bool>(n + 1, false));
	queue<pair<int, int>> q;

	q.push({ 1, 1 });
	visited[1][1] = true, light[1][1] = true;

	int cnt = 1;

	while (q.size())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (const pair<int, int>& room : board[x][y])
		{
			int rx = room.first, ry = room.second;
			if (light[rx][ry] == false)
			{
				light[rx][ry] = true;
				cnt++;

				for (int i = 0; i < 4; i++)
				{
					int nx = rx + dx[i], ny = ry + dy[i];

					if (ny < 1 || nx < 1 || ny > n || nx > n) continue;

					if (visited[nx][ny] && visited[rx][ry] == false)
					{
						visited[rx][ry] = true;
						q.push({ rx, ry });
						break;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
			if (visited[nx][ny] || light[nx][ny] == false) continue;
			
			q.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	board.assign(n + 1, vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>()));

	for (int i = 0; i < m; i++)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		board[x][y].push_back({ a, b });
	}

	cout << bfs() << "\n";

	return 0;
}