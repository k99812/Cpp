#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

struct Info
{
	int y, x, dir;
};

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

int n, m, k;
vector<vector<vector<int>>> board;
vector<vector<pair<int, int>>> visited;
map<int, Info> shark_pos;
map<pair<int, int>, vector<int>> shark_dir;
vector<bool> shark_alive;

Info getNextpos(int idx)
{
	int y = shark_pos[idx].y, x = shark_pos[idx].x, dir = shark_pos[idx].dir;

	vector<int>& priority = shark_dir[{ idx, dir }];
	vector<Info> candi;

	for (int nd : priority)
	{
		int ny = y + dy[nd], nx = x + dx[nd];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx].second == 0)
		{
			return { ny, nx, nd };
		}
		else if (visited[ny][nx].first == idx)
		{
			candi.push_back({ ny, nx, nd });
		}
	}

	if (candi.empty()) return { y, x, dir };
	return candi[0];
}

int go()
{
	int time = 0;
	while (time <= 1000)
	{
		bool flag = true;
		for (int i = 2; i <= m; i++)
		{
			if (shark_pos[i].y != -1)
			{
				flag = false;
				break;
			}
		}

		if (flag) return time;

		vector<vector<vector<int>>> next_board(n, vector<vector<int>>(n));

		for (int idx = 1; idx <= m; idx++)
		{
			if (shark_pos[idx].y == -1) continue;

			Info next = getNextpos(idx);
			next_board[next.y][next.x].push_back(idx);
			shark_pos[idx] = next;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (next_board[i][j].size() >= 2)
				{
					sort(next_board[i][j].begin(), next_board[i][j].end());

					for (int itr = 1; itr < next_board[i][j].size(); itr++)
					{
						int idx = next_board[i][j][itr];
						shark_pos[idx] = { -1, -1, -1 };
					}
					next_board[i][j].resize(1);
				}
			}
		}

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				if (visited[i][j].first > 0 && --visited[i][j].second == 0)
				{
					visited[i][j] = { 0, 0 };
				}
			}
		}

		for (int i = 1; i <= m; i++) 
		{
			if (shark_pos[i].y == -1) continue;

			int y = shark_pos[i].y;
			int x = shark_pos[i].x;
			visited[y][x] = { i, k };
		}

		board = next_board;
		time++;
	}

	return -1;
}

int main()
{
	cin >> n >> m >> k;

	board = vector<vector<vector<int>>>(n, vector<vector<int>>(n));
	visited = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int shark;
			cin >> shark;

			if (shark)
			{
				board[i][j].push_back(shark);
				shark_pos[shark] = { i, j, -1 };
				visited[i][j] = { shark, k };
			}
		}
	}

	for (int i = 1; i <= m; i++)
	{
		int d;
		cin >> d;
		shark_pos[i].dir = --d;
	}

	for (int idx = 1; idx <= m; idx++)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			shark_dir[{ idx, dir }].resize(4);

			for (int i = 0; i < 4; i++)
			{
				int d;
				cin >> d;
				shark_dir[{ idx, dir }][i] = --d;
			}
		}
	}

	cout << go() << "\n";

	return 0;
}