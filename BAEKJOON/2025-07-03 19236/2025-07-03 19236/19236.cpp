#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };


int go(int y, int x, vector<vector<pair<int, int>>> board, map<int, pair<int, int>> fish)
{
	int idx = board[y][x].first, dir = board[y][x].second;
	
	fish[idx] = { -1, -1 };
	board[y][x] = { 0, -1 };

	for (int i = 1; i <= 16; i++)
	{
		int cy = fish[i].first, cx = fish[i].second;
		if (cy == -1) continue;

		int d = board[cy][cx].second;
		for (int j = 0; j < 8; j++)
		{
			int nd = (d + j) % 8;
			int ny = cy + dy[nd], nx = cx + dx[nd];

			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (ny == y && nx == x) continue;

			if (board[ny][nx].first > 0)
			{
				fish[board[ny][nx].first] = { cy, cx };
			}

			swap(board[ny][nx], board[cy][cx]);
			fish[i] = { ny, nx };
			board[ny][nx].second = nd;
			break;
		}
	}

	int sum = idx;
	for (int i = 1; i <= 3; i++)
	{
		int ny = y + dy[dir] * i, nx = x + dx[dir] * i;

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) break;
		if (board[ny][nx].first == 0) continue;

		sum = max(sum, go(ny, nx, board, fish) + idx);
	}

	return sum;
}

int main()
{
	vector<vector<pair<int, int>>> board(4, vector<pair<int, int>>(4));
	map<int, pair<int, int>> fish;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int a, b; cin >> a >> b;
			board[i][j] = { a, b - 1 };
			fish[a] = { i, j };
		}
	}

	cout << go(0, 0, board, fish) << "\n";

	return 0;
}