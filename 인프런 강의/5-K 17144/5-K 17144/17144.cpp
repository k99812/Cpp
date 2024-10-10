#include<iostream>
#include<algorithm>
#include<tuple>
#include<queue>
#include<vector>

using namespace std;

int r, c, t, a[54][54], b[54][54], ret, n;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int cy1[] = { 0, -1, 0, 1 };
int cy2[] = { 0, 1, 0, -1 };
int cx1[] = { 1, 0, -1, 0 };
int cx2[] = { 1, 0, -1, 0 };

vector<pair<int, int>> pos, v1, v2;

void spread(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (a[ny][nx] == -1) continue;
		cnt++;
		b[ny][nx] += a[y][x] / 5;
	}
	b[y][x] += a[y][x] - ((a[y][x] / 5) * cnt);
}

vector<pair<int, int>> chu(int sy, int sx, int dy[], int dx[])
{
	vector<pair<int, int>> v;
	int cnt = 0;
	int y = sy;
	int x = sx;

	while (true)
	{
		int ny = y + dy[cnt], nx = x + dx[cnt];
		if (ny == sy && nx == sx) break;
		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
		{
			cnt++;
			ny = y + dy[cnt];
			nx = x + dx[cnt];
		}
		if (ny == sy && nx == sx) break;
		v.push_back({ ny, nx });
		y = ny; x = nx;
	}
	return v;
}


void go(vector<pair<int, int>> &v)
{
	for (int i = v.size() - 1; i > 0; i--)
	{
		a[v[i].first][v[i].second] = a[v[i - 1].first][v[i - 1].second];
	}
	a[v[0].first][v[0].second] = 0;
	return;
}

int main()
{
	cin >> r >> c >> t;
	bool flage = true;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == -1)
			{
				pos.push_back({ i, j });
				if (flage)
				{
					v1 = chu(pos[0].first, pos[0].second, cy1, cx1);
					flage = false;
				}
				else
				{
					v2 = chu(pos[1].first, pos[1].second, cy2, cx2);
				}
			}
		}
	}

	while (n < t)
	{
		//spread fild
		fill(&b[0][0], &b[53][54], 0);
		b[pos[0].first][pos[0].second] = -1;
		b[pos[1].first][pos[1].second] = -1;

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (a[i][j] == 0 || a[i][j] == -1) continue;
				spread(i, j);
			}
		}
		copy(&b[0][0], &b[53][54], &a[0][0]);
		go(v1);
		go(v2);
		n++;
	}

	for (int i = 0; i < r ; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] != -1) ret += a[i][j];
		}
	}

	cout << "\n";
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j] << "  ";
		}
		cout << "\n";
	}

	cout << ret << "\n";

	return 0;
}