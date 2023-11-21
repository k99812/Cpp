#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int s, m, n, ret, a[1001], b[1001], psum_a[2002], psum_b[2002];
map<int, int> aCnt, bCnt;

void go(int n, int psum[], map<int, int>& m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n + i - 1; j++)
		{
			int sum = psum[j] - psum[j - i];
			m[sum]++;
			if (i == n) break;
		}
	}
}

int main()
{
	cin >> s >> m >> n;

	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
		psum_a[i] = psum_a[i - 1] + a[i];
	}

	for (int i = m + 1; i <= 2 * m; i++)
	{
		psum_a[i] = psum_a[i - 1] + a[i - m];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		psum_b[i] = psum_b[i - 1] + b[i];
	}

	for (int i = n + 1; i <= 2 * n; i++)
	{
		psum_b[i] = psum_b[i - 1] + b[i - n];
	}
	 
	go(m, psum_a, aCnt);
	go(n, psum_b, bCnt);
	ret = (aCnt[s] + bCnt[s]);
	for (int i = 1; i < s; i++)
	{
		ret += (aCnt[i] * bCnt[s - i]);
	}
	cout << ret << "\n";

	return 0;
}