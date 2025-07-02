#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
	int r,
		c,
		m,
		s,
		d;
};

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int dirAll[] = { 0, 2, 4, 6 };
const int dirNot[] = { 1, 3, 5, 7 };

int n, m, k;
vector<Info> fireball;
vector<vector<vector<Info>>> grid;

void go()
{
	grid = vector<vector<vector<Info>>>(n, vector<vector<Info>>(n));

	for (Info& fire : fireball)
	{
		int ny = (fire.r + (dy[fire.d] * fire.s) + n * 1000) % n;
		int nx = (fire.c + (dx[fire.d] * fire.s) + n * 1000) % n;

		grid[ny][nx].push_back({ ny, nx, fire.m, fire.s, fire.d });
	}

	fireball.clear();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j].empty()) continue;

			if (grid[i][j].size() == 1)
			{
				fireball.push_back(grid[i][j][0]);
				continue;
			}

			int sum_m = 0, sum_s = 0;
			bool odd = false, even = false;
			int cnt = grid[i][j].size();

			for (Info& fire : grid[i][j])
			{
				sum_m += fire.m;
				sum_s += fire.s;
				fire.d % 2 ? odd = true : even = true;
			}

			int nm = sum_m / 5;
			if (nm == 0) continue;

			int ns = sum_s / cnt;
			for (int k = 0; k < 4; k++)
			{
				int ndir = (odd && even) ? dirNot[k] : dirAll[k];
				fireball.push_back({ i, j, nm, ns, ndir });
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	fireball = vector<Info>(m);

	for (int i = 0; i < m; i++)
	{
		cin >> fireball[i].r >> fireball[i].c >> fireball[i].m
			>> fireball[i].s >> fireball[i].d;

		--fireball[i].r, --fireball[i].c;
	}

	while (k--)
	{
		go();
	}

	int ret = 0;
	for (const Info& fire : fireball)
	{
		ret += fire.m;
	}

	cout << ret << "\n";

	return 0;
}