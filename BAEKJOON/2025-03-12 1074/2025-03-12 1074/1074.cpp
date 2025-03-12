#include<iostream>
#include<algorithm>

using namespace std;

int n, r, c, ret;

int go(int n, int y, int x)
{
	if (n == 0) return 0;

	int mid = (1 << n - 1);
	int size = mid * mid;

	if (y < mid && x < mid)
	{
		return go(n - 1, y, x);
	}
	else if (y < mid && x >= mid)
	{
		return size + go(n - 1, y, x - mid);
	}
	else if (y >= mid && x < mid)
	{
		return 2 * size + go(n - 1, y - mid, x);
	}
	else
	{
		return 3 * size + go(n - 1, y - mid, x - mid);
	}
}

int main()
{
	cin >> n >> r >> c;

	cout << go(n, r, c) << "\n";

	return 0;
}