#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int n = 8, WALL = 1, BLANK = 0;
const int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };

vector<vector<int>> board;
vector<pair<int, int>> walls;
pair<int, int> start = { 7, 0 }, des = { 0, 7 };

bool go()
{
	queue<pair<int, int>> q;
	q.push({ start });

	while (q.size())
	{
		int qSize = q.size();
		vector<vector<bool>> visited(n, vector<bool>(n));

		while (qSize--)
		{
			int y = q.front().first, x = q.front().second;
			q.pop();

			if (y == des.first && x == des.second) return true;
			if (board[y][x] == WALL) continue;

			for (int i = 0; i < 9; i++)
			{
				int ny = y + dy[i], nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (board[ny][nx] == WALL || visited[ny][nx]) continue;

				visited[ny][nx] = true;
				q.push({ ny, nx });
			}
		}

		for (pair<int, int>& wall : walls) 
		{
			if (wall.first != -1) 
			{
				board[wall.first][wall.second] = BLANK;
			}
		}

		for (pair<int, int>& wall : walls) 
		{
			if (wall.first != -1) 
			{
				wall.first++;
				if (wall.first >= n)
				{
					wall = { -1, -1 };
					continue;
				}

				board[wall.first][wall.second] = WALL;
			}
		}
	}

	return false;
}

int main()
{
	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = s[j] == '#' ? WALL : BLANK;
			if (s[j] == '#') walls.push_back({ i, j });
		}
	}

	bool flag = go();
	cout << (flag ? 1 : 0) << "\n";

	return 0;
}