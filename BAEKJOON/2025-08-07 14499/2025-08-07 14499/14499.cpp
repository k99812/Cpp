#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0, 0 };

int n, m, x, y, k;
vector<vector<int>> board;
vector<int> dice(6); // 0: À­¸é, 1: ºÏ, 2: µ¿, 3: ¼­, 4: ³², 5: ¹Ù´Ú¸é

int go(int dir)
{
	int ny = y + dy[dir], nx = x + dx[dir];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m) return -1;

	y = ny, x = nx;

	vector<int> temp = dice;

	if (dir == 0)
	{
		dice[0] = temp[3];
		dice[2] = temp[0];
		dice[5] = temp[2];
		dice[3] = temp[5];
	}
	else if (dir == 1)
	{
		dice[0] = temp[2];
		dice[3] = temp[0];
		dice[5] = temp[3];
		dice[2] = temp[5];
	}
	else if (dir == 2)
	{
		dice[0] = temp[4];
		dice[1] = temp[0];
		dice[5] = temp[1];
		dice[4] = temp[5];
	}
	else if (dir == 3)
	{
		dice[0] = temp[1];
		dice[4] = temp[0];
		dice[5] = temp[4];
		dice[1] = temp[5];
	}

	if (board[y][x] == 0)
	{
		board[y][x] = dice[5];
	}
	else
	{
		dice[5] = board[y][x];
		board[y][x] = 0;
	}

	return dice[0];
}

int main()
{
	cin >> n >> m >> y >> x >> k;

	board = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int d;
		cin >> d;

		int ret = go(--d);
		if (ret != -1) cout << ret << "\n";
	}

	return 0;
}