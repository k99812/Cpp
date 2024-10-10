#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, a[104], b[104], dp[104][10][10][10][2];
string s, s2;

int mod_(int x)
{
	return (x < 0) ? x + 10 : x % 10;
}

int go(int pos, int x, int y, int z, int flag)
{
	if (pos == n) return 0;

	int& ret = dp[pos][x][y][z][flag];
	if (ret != -1) return ret;

	ret = 1e9;
	if (mod_(x + a[pos]) == mod_(b[pos])) return ret = min(go(pos + 1, y, z, 0, 0), go(pos + 1, y, z, 0, 1));

	int unit = flag ? 1 : -1;
	for (int i = 1; i <= 3; i++)
	{
		ret = min(ret, go(pos, mod_(x + i * unit), y, z, flag) + 1);
		ret = min(ret, go(pos, mod_(x + i * unit), mod_(y + i * unit), z, flag) + 1);
		ret = min(ret, go(pos, mod_(x + i * unit), mod_(y + i * unit), mod_(z + i * unit), flag) + 1);
	}
	return ret;
}

int main()
{
	cin >> n >> s >> s2;

	for (int i = 0; i < n; i++)
	{
		a[i] = s[i] - '0';
		b[i] = s2[i] - '0';
	}

	fill(&dp[0][0][0][0][0], &dp[103][9][9][9][2], -1);

	cout << min(go(0, 0, 0, 0, 0), go(0, 0, 0, 0, 1)) << "\n";

	return 0;
}