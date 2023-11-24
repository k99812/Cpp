#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

const int MAX = 54;
int n, m, _map[MAX][MAX], visited[MAX][MAX], roomCnt, roomMax = -1, compSize[2504], breakRoom = -1;
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
queue<pair<int, int>> q;

int bfs(int y, int x)
{
	q.push({ y, x });
	visited[y][x] = roomCnt;
	int roomArea = 1;

	while (q.size())
	{
		int ty, tx;
		tie(ty, tx) = q.front(); 
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i], nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (_map[ty][tx] & (1 << i)) continue;
			visited[ny][nx] = roomCnt;
			roomArea++;
			q.push({ ny, nx });
		}
	}
	return roomArea;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> _map[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			roomCnt++;
			compSize[roomCnt] = bfs(i, j);
			roomMax = max(compSize[roomCnt], roomMax);
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + 1 < m)
			{
				int ARoom = visited[i][j], BRoom = visited[i + 1][j];
				if (ARoom != BRoom)
				{
					breakRoom = max(breakRoom, compSize[ARoom] + compSize[BRoom]);
				}
			}
			if (j + 1 < n)
			{
				int ARoom = visited[i][j], BRoom = visited[i][j + 1];
				if (ARoom != BRoom)
				{
					breakRoom = max(breakRoom, compSize[ARoom] + compSize[BRoom]);
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= 5; i++)
	{
		cout << " " << compSize[i] << " ";
	}
	cout << "\n";

	cout << roomCnt << "\n";
	cout << roomMax << "\n";
	cout << breakRoom << "\n";
	return 0;
}