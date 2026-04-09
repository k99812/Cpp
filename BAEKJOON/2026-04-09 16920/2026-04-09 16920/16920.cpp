#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n, m, p;
vector<int> speed;
vector<string> board;
vector<vector<pair<int, int>>> player;

vector<int> bfs()
{
	vector<queue<pair<int, int>>> q(p + 1, queue<pair<int, int>>());
	vector<int> ans(p + 1);

	for (int i = 1; i <= p; i++)
	{
		for (const pair<int, int>& p : player[i])
		{
			q[i].push(p);
			ans[i]++;
		}
	}
	
	while (true)
	{
		bool is_extended = false;

		for(int turn = 1; turn <= p; turn++)
		{
			if (q[turn].empty()) continue;

			for (int step = 0; step < speed[turn]; step++)
			{
				if (q[turn].empty()) break;

				int q_size = q[turn].size();

				while (q_size--)
				{
					int y = q[turn].front().first, x = q[turn].front().second;
					q[turn].pop();

					for (int i = 0; i < 4; i++)
					{
						int ny = y + dy[i], nx = x + dx[i];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (board[ny][nx] != '.') continue;

						board[ny][nx] = turn + '0';
						q[turn].push({ ny, nx });
						ans[turn]++;
						is_extended = true;
					}
				}
			}
		}

		if (!is_extended) break;
	}

	return ans;
}

int main()
{
	cin >> n >> m >> p;

	board.assign(n, "");
	speed.assign(p + 1, 0);
	player.assign(p + 1, vector<pair<int, int>>());

	for (int i = 1; i <= p; i++)
	{
		cin >> speed[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
		for (int j = 0; j < m; j++)
		{
			if (isdigit(board[i][j]))
			{
				int idx = board[i][j] - '0';
				player[idx].push_back({ i, j });
			}
		}
	}

	vector<int> ret = bfs();
	for (int i = 1; i <= p; i++)
	{
		cout << ret[i] << " ";
	}
	cout << "\n";

	return 0;
}