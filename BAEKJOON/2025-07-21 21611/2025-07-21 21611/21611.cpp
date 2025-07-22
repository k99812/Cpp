#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

const int dy[2][4] = { { -1, 1, 0, 0 }, { 0, 1, 0, -1} };
const int dx[2][4] = { { 0, 0, -1, 1 }, { -1, 0, 1, 0} };

int n, m;
vector<vector<int>> board;
pair<int, int> shark;
unordered_map<int, int> ret;

void move(vector<vector<int>>& temp)
{

}

bool destroy()
{
	int y = shark.first, x = shark.second;
	int cnt = 0, s = 1, dir = 0, num_cnt = 1;

	vector<vector<int>> temp = board;
	vector<pair<int, int>> cordi;

	while (true)
	{
		if ((y == 0 && x == 0) || temp[y][x] == 0) break;

		if (cnt != 0 && cnt % 2 == 0) ++s;

		for (int step = 1; step <= s; step++)
		{
			int ny = y + dy[1][dir], nx = x + dx[1][dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
			if (temp[ny][nx] == 0)
			{
				y = ny, x = nx;
				break;
			}

			if (temp[y][x] != temp[ny][nx])
			{
				if (num_cnt >= 4)
				{
					for (const pair<int, int>& itr : cordi)
					{
						temp[itr.first][itr.second] = 0;
					}

					move(temp);

					y = shark.first, x = shark.second;
					cnt = 0, s = 1, dir = 0;
					board = temp;
				}

				if(cordi.size()) cordi.clear();
				num_cnt = 1;
			}
			else
			{
				cordi.push_back({ ny, nx });
				++num_cnt;
			}

			y = ny, x = nx;
		}

		++cnt;
		dir = (dir + 1) % 4;
	}

	board = temp;
}

void go(int d, int s)
{
	int y = shark.first, x = shark.second;
	vector<vector<int>> temp = board;

	for (int i = 1; i <= s; i++)
	{
		int ny = y + dy[0][d] * i, nx = x + dx[0][d] * i;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n) break;
		if (temp[ny][nx] == 0) continue;

		temp[ny][nx] = 0;
	}

	move(temp);
	board = temp;

	while (true)
	{
		bool flag = destroy();
		if (!flag) break;
	}
}

int main()
{
	cin >> n >> m;

	shark = { (n + 1) / 2, (n + 1) / 2 };
	board = vector<vector<int>>(n, vector<int>(n));
	ret[1] = 0, ret[2] = 0, ret[3] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}  

	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;

		go(--d, s);
	}
	
	return 0;
}