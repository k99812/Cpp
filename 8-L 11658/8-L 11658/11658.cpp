#include<iostream>
#include<algorithm>

using namespace std;

int n, m, a[1030][1030], tree[1030][1030], w, x, y, x2, y2, c;

void update(int y, int x, int value)
{
	while (y <= n)
	{
		int j = x;
		while (j <= n)
		{
			tree[y][j] += value;
			j += (j & -j);
		}
		y += (y & -y);
	}
}

int sum(int y, int x)
{
	int ret = 0;
	while (y > 0)
	{
		int j = x;
		while (j > 0)
		{
			ret += tree[y][j];
			j -= (j & -j);
		}
		y -= (y & -y);
	}
	return ret;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			update(i, j, a[i][j]);
		}
	}

	while (m--)
	{
		cin >> w;

		if (w)
		{
			cin >> y >> x >> y2 >> x2;
			cout << sum(y2, x2) - sum(y - 1, x2) - sum(y2, x - 1) + sum(y - 1, x - 1) << "\n";
		}
		else
		{
			cin >> y >> x >> c;
			update(y, x, c - a[y][x]);
			a[y][x] = c;
		}
	}

	return 0;
}