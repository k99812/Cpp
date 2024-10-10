#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX_N = 100;
struct Shark
{
	int y;
	int x;
	int s;
	int dir;
	int z;
	int bIsdead;
}a[MAX_N * MAX_N];
const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };
int r, c, m, ret, shark[MAX_N][MAX_N], temp[MAX_N][MAX_N];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y--; a[i].x--; a[i].dir--;

		if (a[i].dir <= 1) a[i].s %= (2 * (r - 1));
		else a[i].s %= (2 * (c - 1));

		shark[a[i].y][a[i].x] = i;
	}

	for (int t = 0; t < c; t++)
	{
		for (int y = 0; y < r; y++)
		{
			if (shark[y][t])
			{
				a[shark[y][t]].bIsdead = 1;
				ret += a[shark[y][t]].z;
				shark[y][t] = 0;
				break;
			}
		}

		fill(&temp[0][0], &temp[MAX_N - 1][MAX_N], 0);
		for (int i = 1; i <= m; i++)
		{
			if (a[i].bIsdead) continue;

			int y = a[i].y;
			int x = a[i].x;
			int d = a[i].dir;
			int s = a[i].s;
			int ny, nx;

			while (true)
			{
				ny = y + s * dy[d];
				nx = x + s * dx[d];
				if (ny < r && nx < c && ny >= 0 && nx >= 0) break;
				if (d <= 1)
				{
					if (ny < 0)
					{
						s -= y;
						y = 0;
					}
					else
					{
						s -= r - 1 - y;
						y = r - 1;
					}
				}
				else
				{
					if (nx < 0)
					{
						s -= x;
						x = 0;
					}
					else
					{
						s -= c - 1 - x;
						x = c - 1;
					}
				}
				d ^= 1;
			}

			if (temp[ny][nx])
			{
				if (a[temp[ny][nx]].z < a[i].z)
				{
					a[temp[ny][nx]].bIsdead = 1;
					temp[ny][nx] = i;
				}
				else a[i].bIsdead = 1;
			}
			else
			{
				temp[ny][nx] = i;
			}

			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		copy(&temp[0][0], &temp[MAX_N - 1][MAX_N], &shark[0][0]);
	}

	cout << ret << "\n";

	return 0;
}