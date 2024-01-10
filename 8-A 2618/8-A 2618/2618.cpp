#include<iostream>
#include<algorithm>

using namespace std;

int n, w, x, y, px[1003], py[1003], dp[1003][1003];

int ab(int a, int b)
{
	return abs(px[a] - px[b]) + abs(py[a] - py[b]);
}

int go(int a, int b)
{
	if (a == w + 1 || b == w + 1) return 0;

	int& ret = dp[a][b];
	if (ret) return ret;

	int nx = max(a, b) + 1;
	return ret = min(go(a, nx) + ab(b, nx), go(nx, b) + ab(a, nx));
}

void trace()
{
	int a = 0, b = 1;
	for (int i = 2; i < w + 2; i++)
	{
		if (dp[i][b] + ab(a, i) < dp[a][i] + ab(b, i))
		{
			cout << 1 << "\n";
			a = i;
		}
		else
		{
			cout << 2 << "\n";
			b = i;
		}
	}
}

int main()
{
	cin >> n >> w;

	px[0] = 1, py[0] = 1;
	px[1] = n, py[1] = n;

	for (int i = 2; i < w + 2; i++)
	{
		cin >> y >> x;
		py[i] = y, px[i] = x;
	}

	cout << go(0, 1) << "\n";
	trace();

	return 0;
}