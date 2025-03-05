#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> ret(2);

void go(int y, int x, int cnt, int color, const vector<vector<int>>& map, vector<int>& left, vector<int>& right)
{
	if (x >= n)
	{
		++y;

		x = (x % 2 ? 0 : 1);
	}

	if (y >= n)
	{
		ret[color] = max(ret[color], cnt);
		return;
	}

	if (map[y][x] && !left[y - x + n - 1] && !right[y + x])
	{
		left[y - x + n - 1] = 1, right[y + x] = 1;
		go(y, x + 2, cnt + 1, color, map, left, right);
		left[y - x + n - 1] = 0, right[y + x] = 0;
	}
	go(y, x + 2, cnt, color, map, left, right);
}

int main()
{
	cin >> n;

	vector<vector<int>> map(n, vector<int>(n));

	vector<int> left(2 * n - 1), right(2 * n - 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	go(0, 0, 0, 0, map, left, right);
	go(0, 1, 0, 1, map, left, right);

	cout << ret[0] + ret[1] << "\n";

	return 0;
}