#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define MAX_NUM 20 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, M[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM][1 << 10];
string s;

int bfs(int y, int x, int bit)
{
	fill(&visited[0][0][0], &visited[MAX_NUM - 1][MAX_NUM - 1][1 << 10], 0);
	queue<pair<int, int>> pos_q, bit_q;
	pos_q.push({ y, x });
	bit_q.push({ 0, 0 });
	visited[y][x][0] = true;

	while (bit_q.size())
	{
		int cd = bit_q.front().first, cb = bit_q.front().second;
		int cy = pos_q.front().first, cx = pos_q.front().second;
		bit_q.pop(); pos_q.pop();

		if (cb == (1 << bit) - 1) return cd;

		for (int i = 0; i < 4; i++)
		{
			int nd = cd + 1, nb = cb;
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny > n || nx > m || M[ny][nx] == -1) continue;
			if (M[ny][nx] > 0) nb |= (1 << (M[ny][nx] - 1));
			if (visited[ny][nx][nb]) continue;

			visited[ny][nx][nb] = true;
			bit_q.push({ nd,nb });
			pos_q.push({ ny,nx });
		}
	}

	return -1;
}

int main()
{
	while (cin >> m >> n)
	{
		if (n == 0 && m == 0) break;

		fill(&M[0][0], &M[MAX_NUM - 1][MAX_NUM], -1);

		int cnt = 0;
		pair<int, int> start;

		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < m; j++)
			{
				if (s[j] == 'o')
				{
					M[i][j] = 0;
					start = { i, j };
				}
				else if (s[j] == 'x')
				{
					M[i][j] = -1;
				}
				else if (s[j] == '*')
				{
					M[i][j] = ++cnt;
				}
				else
				{
					M[i][j] = 0;
				}
			}
		}

		cout << bfs(start.first, start.second, cnt) << "\n";
	}

	return 0;
}