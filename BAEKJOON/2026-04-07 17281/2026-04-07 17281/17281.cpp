#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int SIZE = 9;

int n, ret = 0;
int sequence[9];
bool visited[SIZE];
vector<vector<int>> board;

void dfs(int idx)
{
	if (idx == SIZE)
	{
		int point = 0, start_idx = 0;

		for (int inning = 0; inning < n; inning++)
		{
			int out_cnt = 0, runner = 0;

			while (out_cnt < 3)
			{
				int hit = board[inning][sequence[start_idx]];
				start_idx = (start_idx + 1) % SIZE;

				if (hit == 0)
				{
					out_cnt++;
					continue;
				}

				runner |= 1;
				runner <<= hit;
				point += __builtin_popcount(runner >> 4);
				runner &= 14;
			}
		}

		ret = max(ret, point);
		return;
	}

	if (idx == 3)
	{
		dfs(idx + 1);
		return;
	}

	for (int i = 1; i <= 8; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		sequence[idx] = i;

		dfs(idx + 1);

		visited[i] = false;
		sequence[idx] = 0;
	}
}

int main()
{
	cin >> n;

	board.assign(n, vector<int>(SIZE, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cin >> board[i][j];
		}
	}

	visited[0] = true;
	sequence[3] = 0;

	dfs(0);

	cout << ret << "\n";

	return 0;
}