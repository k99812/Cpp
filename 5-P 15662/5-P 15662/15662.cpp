#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n, k, a, b, ret;
string s[1004];

void rot(int pos, int dir)
{
	if (dir != 1)
	{
		rotate(s[pos].begin(), s[pos].begin() + 1, s[pos].end());
	}
	else
	{
		rotate(s[pos].begin(), s[pos].end() - 1, s[pos].end());
	}
}

int findL(int pos)
{
	for (int i = pos; i >= 1; i--)
	{
		if (s[i][6] == s[i - 1][2])
		{
			return i;
		}
	}
	return 0;
}

int findR(int pos)
{
	for (int i = pos; i < n - 1; i++)
	{
		if (s[i][2] == s[i + 1][6])
		{
			return i;
		}
	}
	return n - 1;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}

	cin >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b; a--;

		int l = findL(a);
		int r = findR(a);

		int cnt = 0;
		for (int j = a; j >= l; j--)
		{
			rot(j, cnt % 2 == 0 ? b : -b);
			cnt++;
		}

		cnt = 1;
		for (int j = a + 1; j <= r; j++)
		{
			rot(j, cnt % 2 == 0 ? b : -b);
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) if (s[i][0] == '1') ret++;
	cout << ret << "\n";

	return 0;
}