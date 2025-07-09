#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { -1, 0, 1, 0 };
const vector<std::vector<std::pair<int, int>>> spread = {
	{
		{-1, 1}, {1, 1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, -1}, {1, -1}, {0, -2}
	},

	{
		{-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {1, -1}, {1, 1}, {2, 0}
	},

	{
		{-1, -1}, {1, -1}, {-1, 0}, {1, 0}, {-2, 0}, {2, 0}, {-1, 1}, {1, 1}, {0, 2}
	},

	{
		{1, -1}, {1, 1}, {0, -1}, {0, 1}, {0, -2}, {0, 2}, {-1, -1}, {-1, 1}, {-2, 0}
	}
};

const double spread_ratio[] = { 0.01, 0.01, 0.07, 0.07, 0.02, 0.02, 0.1, 0.1, 0.05 };

int n;
vector<vector<int>> board;
map<pair<int, pair<int, int>>, float> sand_persent;

int sand(int y, int x, int dir)
{
	if (board[y][x] == 0) return 0;

	int out_sand = 0;
	int original_sand = board[y][x];
	int remaining_sand = original_sand;

	for (int i = 0; i < 9; ++i)
	{
		int spread_amount = (int)(original_sand * spread_ratio[i]);
		if (spread_amount == 0) continue;

		remaining_sand -= spread_amount;

		int ny = y + spread[dir][i].first;
		int nx = x + spread[dir][i].second;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) {
			out_sand += spread_amount;
		}
		else {
			board[ny][nx] += spread_amount;
		}
	}

	int ay = y + dy[dir];
	int ax = x + dx[dir];

	if (ay < 0 || ax < 0 || ay >= n || ax >= n) {
		out_sand += remaining_sand;
	}
	else {
		board[ay][ax] += remaining_sand;
	}

	board[y][x] = 0;

	return out_sand;
}

int tornado()
{
	int y = n / 2, x = n / 2;
	int sum = 0, dir = 0, cnt = 0, step = 1;

	while (true)
	{
		if (y == 0 && x == 0) break;

		if (cnt != 0 && cnt % 2 == 0)
		{
			++step;
		}

		int step_cnt = 0;
		while (step_cnt++ < step)
		{
			int ny = y + dy[dir], nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;

			sum += sand(ny, nx, dir);
			y = ny, x = nx;
		}

		++cnt;
		dir = (dir + 1) % 4;
	}

	return sum;
}

int main()
{
	cin >> n;
	
	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << tornado() << "\n";

	return 0;
}