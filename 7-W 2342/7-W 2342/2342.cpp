#include<iostream>
#include<algorithm>

using namespace std;

int n, a[100004], dp[5][5][100004], num;

int check(int from, int to)
{
	if (from == 0) return 2;

	if (from == to) return 1;

	if (abs(to - from) == 2) return 4;

	return 3;
}

int go(int y, int x, int idx)
{
	if (idx == num) return 0;

	int& ret = dp[y][x][idx];
	if (ret) return ret;

	int left = go(a[idx], x, idx + 1) + check(y, a[idx]);
	int right = go(y, a[idx], idx + 1) + check(x, a[idx]);
	return ret = min(left, right);
}

int main()
{
	while (cin >> n)
	{
		if (n == 0) break;

		a[num] = n;
		num++;
	}

	cout << go(0, 0, 0) << "\n";

	return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          