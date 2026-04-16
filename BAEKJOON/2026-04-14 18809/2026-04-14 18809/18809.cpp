#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int RED = 1;
const int GREEN = 2;
const int FLOWER = 3;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, g, r, ret;
vector<pair<int, int>> arr;
vector<vector<int>> board;

int bfs(vector<int>& choose)
{
	queue<pair<int, int>> red_q, green_q;
	vector<vector<int>> state(n, vector<int>(m, 0));
	vector<vector<int>> time_map(n, vector<int>(m, 0));

	int cnt = 0;
	for (int i = 0; i < choose.size(); i++)
	{
		if (choose[i] == RED)
		{
			red_q.push(arr[i]);
			state[arr[i].first][arr[i].second] = RED;
		}

		if (choose[i] == GREEN) 
		{ 
			green_q.push(arr[i]);
			state[arr[i].first][arr[i].second] = GREEN;
		}
	}

	int time = 0;
	while (red_q.size() || green_q.size())
	{
		time++;
		
		if (red_q.size())
		{
			int s = red_q.size();
			while (s--)
			{
				int y = red_q.front().first, x = red_q.front().second;
				red_q.pop();

				if (state[y][x] == FLOWER) continue;

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i], nx = x + dx[i];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (board[ny][nx] == 0 || state[ny][nx]) continue;

					state[ny][nx] = RED;
					time_map[ny][nx] = time;
					red_q.push({ ny, nx });
				}
			}
		}

		if (green_q.size())
		{
			int s = green_q.size();
			while (s--)
			{
				int y = green_q.front().first, x = green_q.front().second;
				green_q.pop();

				for (int i = 0; i < 4; i++)
				{
					int ny = y + dy[i], nx = x + dx[i];

					if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
					if (board[ny][nx] == 0) continue;

					if (state[ny][nx] == 0)
					{
						state[ny][nx] = GREEN;
						time_map[ny][nx] = time;
						green_q.push({ ny, nx });
					}
					else if (state[ny][nx] == RED && time_map[ny][nx] == time)
					{
						cnt++;
						state[ny][nx] = FLOWER;
					}
				}
			}
		}
	}

	return cnt;
}

void dfs(int idx, int green, int red, vector<int>& choose)
{
	if (green == g && red == r)
	{
		ret = max(ret, bfs(choose));
		return;
	}

	for (int i = idx; i < arr.size(); i++)
	{
		if (choose[i]) continue;

		if (green < g)
		{
			choose[i] = GREEN;
			dfs(i + 1, green + 1, red, choose);
			choose[i] = 0;
		}

		if (red < r)
		{
			choose[i] = RED;
			dfs(i + 1, green, red + 1, choose);
			choose[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> g >> r;

	board.assign(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				arr.push_back({ i, j });
			}
		}
	}

	vector<int> choose(arr.size(), 0);
	dfs(0, 0, 0, choose);

	cout << ret << "\n";

	return 0;
}