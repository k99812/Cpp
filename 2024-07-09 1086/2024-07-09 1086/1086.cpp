#include<iostream>
#include<algorithm>
#include<string>

#define MAX_NUM 55

using namespace std;

typedef long long ll;
int n, k;
string num[16];
ll dp[1 << 15][100], a[MAX_NUM], len[MAX_NUM], mul[MAX_NUM], p, q, g;

ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void make_table(int k) 
{
	mul[0] = 1;
	for (int i = 1; i <= 50; i++) 
	{
		mul[i] = mul[i - 1] * 10 % k;
	}
}

ll go(int bit, ll num)
{
	if (bit == (1 << n) - 1)
	{
		return (num % k == 0);
	}

	ll& ret = dp[bit][num];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < n; i++)
	{
		if (bit & (1 << i)) continue;
		ret += go(bit | (1 << i), (num * mul[len[i]] + a[i]) % k);
	}

	return ret;
}

int main()
{
	cin >> n;
	q = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		q *= (i + 1);
	}

	cin >> k;

	for (int i = 0; i < n; i++)
	{
		len[i] = (int)num[i].length();
		int t = 0;
		for (char s : num[i])
		{
			t *= 10; t %= k;
			t += (s - '0'); t %= k;
		}
		a[i] = t;
	}

	make_table(k);
	fill(&dp[0][0], &dp[(1 << 15) - 1][100], -1);

	p = go(0, 0);
	g = gcd(p, q);

	if (p == 0)
	{
		cout << 0 << "/" << 1 << "\n";
	}
	else
	{
		cout << p / g << "/" << q / g << "\n";
	}

	return 0;
}