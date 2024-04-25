#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define MAX_NUM 20 + 4
#define INF 1e9

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, visited[MAX_NUM][MAX_NUM][1 << 10], a[MAX_NUM][MAX_NUM], v[MAX_NUM][MAX_NUM];
string s;

int bfs(int y, int x, int bit)
{
	fill(&visited[0][0][0], &visited[MAX_NUM - 1][MAX_NUM - 1][1 << 10], 0);
	fill(&v[0][0], &v[MAX_NUM - 1][MAX_NUM], 0);
	queue<pair<int, int>> pos_q, bit_q;
	pos_q.push({ y, x });
	bit_q.push({ 0, 0 });
	visited[y][x][0] = 1;

	while (pos_q.size())
	{
		int cd = bit_q.front().first, ck = bit_q.front().second;
		int cy = pos_q.front().first, cx = pos_q.front().second;
		bit_q.pop(); pos_q.pop();

		if (ck == (1 << bit) - 1) return cd;
		for (int i = 0; i < 4; i++)
		{
			int nd = cd + 1, nk = ck;
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == -1) continue;
			if (a[ny][nx] > 0) nk |= (1 << (a[ny][nx] - 1));
			if (visited[ny][nx][nk]) continue;

			bit_q.push({ nd,nk });
			pos_q.push({ ny,nx });
			visited[ny][nx][nk] += true;
		}
	}

	return -1;
}

int main()
{
	while (cin >> m >> n)
	{
		if (n == 0 && m == 0) break;
		fill(&a[0][0], &a[MAX_NUM - 1][MAX_NUM], -1);

		int cnt = 0;
		pair<int, int> start;

		for (int i = 0; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < m; j++)
			{
				if (s[j] == 'o') start = { i, j }, a[i][j] = 0;
				else if (s[j] == '*') a[i][j] = ++cnt;
				else if (s[j] == 'x') a[i][j] = -1;
				else a[i][j] = 0;
			}
		}

		cout << bfs(start.first, start.second, cnt) << "\n";
	}

	return 0;
}