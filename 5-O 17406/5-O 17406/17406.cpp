#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e8;
int n, m, k, a[104][104], b[104][104], visited[104][104], ret = INF, r, c, s, sy, sx, ey, ex, dir;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct rcs
{
	int r;
	int c;
	int s;
};
vector<rcs> v;
vector<int> idx;
vector<pair<int, int>> vv;

void go(int y, int x, bool first)
{
	while (true)
	{
		if (!first && y == sy && x == sx) dir++;
		if (!first && y == sy && x == ex) dir++;
		if (!first && y == ey && x == sx) dir++;
		if (!first && y == ey && x == ex) dir++;

		int ny = y + dy[dir], nx = x + dx[dir];
		if (visited[ny][nx]) break;
		vv.push_back({ ny, nx });
		visited[ny][nx] = 1;
		first = false;
		y = ny, x = nx;
	}
	return;
}

void rotate(int y, int x, int cnt)
{
	for (int i = 1; i <= cnt; i++)
	{
		sy = y - 1 * i;
		sx = x - 1 * i;
		ey = y + 1 * i;
		ex = x + 1 * i;

		vv.clear();
		dir = 0;
		fill(&visited[0][0], &visited[103][104], 0);
		vv.push_back({ sy, sx });
		visited[sy][sx] = 1;
		go(sy, sx, true);
		vector<int> vvv;
		for (pair<int, int> a : vv) vvv.push_back(b[a.first][a.second]);
		rotate(vvv.begin(), vvv.end() - 1, vvv.end());
		for (int j = 0; j < vvv.size(); j++) b[vv[j].first][vv[j].second] = vvv[j];
	}
}

void solve()
{
	for (int i : idx)
	{
		rotate(v[i].r, v[i].c, v[i].s);
	}
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += b[i][j];
		}
		ret = min(ret, sum);
	}
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		cin >> r >> c >> s; r--; c--;
		v.push_back({ r, c, s });
		idx.push_back(i);
	}

	do
	{
		copy(&a[0][0], &a[103][104], &b[0][0]);
		solve();
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ret << "\n";

	return 0;
}