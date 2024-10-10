#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1e9;
int n, a[3], dp[64][64][64];
int ad[6][3] = 
{
	{9, 3, 1},
	{9, 1, 3},
	{3, 9, 1},
	{3, 1, 9},
	{1, 9, 3},
	{1, 3, 9}
};

int go(int x, int y, int z)
{
	if (x == 0 && y == 0 && z == 0)
	{
		return 0;
	}

	int& ret = dp[x][y][z];
	if (ret != INF) return ret;
	
	for (int i = 0; i < 6; i++)
	{
		ret = min(ret, go(max(0, x - ad[i][0]), max(0, y - ad[i][1]), max(0, z - ad[i][2])) + 1);
	}
	return ret;
}

int main()
{
	cin >> n;

	fill(&dp[0][0][0], &dp[63][63][64], INF);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << go(a[0], a[1], a[2]) << "\n";

	return 0;
}