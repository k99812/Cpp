#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

struct Block
{
	int block_cnt, rainbow, mark;
	pair<int, int> cordi;

	bool operator<(const Block& other) const
	{
		if (block_cnt != other.block_cnt) return block_cnt < other.block_cnt;
		if (rainbow != other.rainbow) return rainbow < other.rainbow;
		if (cordi.first != other.cordi.first) return cordi.first < other.cordi.first;
		return cordi.second < other.cordi.second;
	}
};

const int blank = -2;
const int dy[] = { -1 , 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m;
vector<vector<int>> board, visited;

void gravity()
{
	for (int j = 0; j < n; j++)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			if (board[i][j] == blank || board[i][j] == -1) continue;

			int r = i;
			while (r + 1 < n && board[r + 1][j] == blank) r++;

			if (r != i)
			{
				board[r][j] = board[i][j];
				board[i][j] = blank;
			}
		}
	}
}

void rotation()
{
	vector<vector<int>> new_board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			new_board[n - 1 - j][i] = board[i][j];
		}
	}

	board = new_board;
}

void erase(const Block& a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] == a.mark)
			{
				board[i][j] = blank;
			}
		}
	}
}

Block bfs(int y, int x, int color, int mark)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = mark;

	pair<int, int> stand = { y, x };
	int block_cnt = 1, rainbow_cnt = 0;

	vector<vector<bool>> local_visited(n, vector<bool>(n));
	if (board[y][x] == 0)
	{
		rainbow_cnt++;
		local_visited[y][x] = true;
	}

	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (board[ny][nx] == -1 || board[ny][nx] == blank) continue;

			if (color == 0)
			{
				color = board[ny][nx];
			}

			if (board[ny][nx] == 0 && !local_visited[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = mark;
				local_visited[ny][nx] = true;
				rainbow_cnt++;
				block_cnt++;
			}
			else if (board[ny][nx] == color && !visited[ny][nx])
			{
				q.push({ ny, nx });
				visited[ny][nx] = mark;
				block_cnt++;
				stand = max(stand, { ny, nx });
			}
		}
	}

	return Block({ block_cnt, rainbow_cnt, mark, stand });
}

int main()
{
	cin >> n >> m;

	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int point = 0;
	while (true)
	{
		int mark = 0;
		Block block;
		visited = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j]) continue;
				if (board[i][j] == -1 || board[i][j] == blank) continue;

				Block temp = bfs(i, j, board[i][j], ++mark);

				if (temp.block_cnt < 2) continue;

				block = max(block, temp);
			}
		}

		if (block.block_cnt < 2) break;

		point += pow(block.block_cnt, 2);
		erase(block);
		gravity();
		rotation();
		gravity();
	}

	cout << point << "\n";

	return 0;
}