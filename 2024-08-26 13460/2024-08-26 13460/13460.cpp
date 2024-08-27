#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define MAX_NUM 12

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, ret, visited[MAX_NUM][MAX_NUM][MAX_NUM][MAX_NUM];;
char a[MAX_NUM][MAX_NUM];
pair<int, int> blue, red;

struct info
{
	int ry, 
		rx, 
		by, 
		bx, 
		cnt;
};

int bfs(int ry, int rx, int by, int bx)
{
	queue<info> q;
	q.push({ ry, rx, by, bx, 0 });
	visited[ry][rx][by][bx] = 1;

	while (q.size())
	{
		int cur_ry = q.front().ry, cur_rx = q.front().rx;
		int cur_by = q.front().by, cur_bx = q.front().bx;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 10) break;

		for (int i = 0; i < 4; i++)
		{
			int next_ry = cur_ry, next_rx = cur_rx;
			int next_by = cur_by, next_bx = cur_bx;
			int next_cnt = cnt + 1, red_dis = 0, blue_dis = 0;

			while (a[next_ry + dy[i]][next_rx + dx[i]] != '#' && a[next_ry][next_rx] != 'O')
			{
				next_ry += dy[i];
				next_rx += dx[i];
				red_dis++;
			}

			while (a[next_by + dy[i]][next_bx + dx[i]] != '#' && a[next_by][next_bx] != 'O')
			{
				next_by += dy[i];
				next_bx += dx[i];
				blue_dis++;
			}

			if (a[next_by][next_bx] == 'O') continue;
			if (a[next_ry][next_rx] == 'O')
			{
				return next_cnt;
			}

			if (next_ry == next_by && next_rx == next_bx)
			{
				if (red_dis < blue_dis)
				{
					next_by -= dy[i];
					next_bx -= dx[i];
				}
				else
				{
					next_ry -= dy[i];
					next_rx -= dx[i];
				}
			}

			if (visited[next_ry][next_rx][next_by][next_bx]) continue;
			visited[next_ry][next_rx][next_by][next_bx] = true;
			q.push({ next_ry, next_rx, next_by, next_bx, next_cnt });
		}
	}

	return -1;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];

			if (a[i][j] == 'R')
			{
				red = { i, j };
			}
			if (a[i][j] == 'B')
			{
				blue = { i, j };
			}
		}
	}

	cout << bfs(red.first, red.second, blue.first, blue.second) << "\n";

	return 0;
}