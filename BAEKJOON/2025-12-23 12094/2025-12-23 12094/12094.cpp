#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, ret = -1;

int get_max(const vector<vector<int>>& board) 
{
	int m = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			m = max(m, board[i][j]);
		}
	}

	return m;
}

vector<vector<int>> move_block(int dir, const vector<vector<int>>& board)
{
	vector<vector<int>> new_board(n, vector<int>(n, 0));

	if (dir == 0)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = 0, temp = 0;
			for (int i = 0; i < n; i++)
			{
				if (board[i][j] == 0) continue;

				if (temp == 0) temp = board[i][j];
				else
				{
					if (temp == board[i][j])
					{
						new_board[idx++][j] = temp * 2;
						temp = 0;
					}
					else
					{
						new_board[idx++][j] = temp;
						temp = board[i][j];
					}
				}
			}
			if (temp != 0) new_board[idx][j] = temp;
		}
	}
	else if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int idx = n - 1, temp = 0;
			for (int j = n - 1; j >= 0; j--)
			{
				if (board[i][j] == 0) continue;

				if (temp == 0) temp = board[i][j];
				else
				{
					if (temp == board[i][j])
					{
						new_board[i][idx--] = temp * 2;
						temp = 0;
					}
					else
					{
						new_board[i][idx--] = temp;
						temp = board[i][j];
					}
				}
			}

			if (temp != 0) new_board[i][idx] = temp;
		}
	}
	else if (dir == 2)
	{
		for (int j = 0; j < n; j++)
		{
			int idx = n - 1, temp = 0;
			for (int i = n - 1; i >= 0; i--)
			{
				if (board[i][j] == 0) continue;

				if (temp == 0) temp = board[i][j];
				else
				{
					if (temp == board[i][j])
					{
						new_board[idx--][j] = temp * 2;
						temp = 0;
					}
					else
					{
						new_board[idx--][j] = temp;
						temp = board[i][j];
					}
				}
			}

			if (temp != 0) new_board[idx][j] = temp;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			int idx = 0, temp = 0;
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 0) continue;

				if (temp == 0) temp = board[i][j];
				else
				{
					if (temp == board[i][j])
					{
						new_board[i][idx++] = temp * 2;
						temp = 0;
					}
					else
					{
						new_board[i][idx++] = temp;
						temp = board[i][j];
					}
				}
			}

			if (temp != 0) new_board[i][idx] = temp;
		}
	}

	return new_board;
}

void go(int idx, vector<vector<int>> board)
{
	int max_block = get_max(board);
	ret = max(ret, max_block);

	if (idx == 10) return;

	if (max_block * (1 << (10 - idx)) <= ret) return;

	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> next_board = move_block(i, board);

		if (board == next_board) continue;

		go(idx + 1, next_board);
	}
}

int main()
{
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	go(0, board);

	cout << ret << "\n";

	return 0;
}