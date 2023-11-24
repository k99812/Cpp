#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 24, INF = 1e8;
int n, ret = INF, map[MAX];
string s;

void go(int here)
{
	if (here == n + 1)
	{
		int sum = 0;
		for (int i = 1; i <= (1 << n - 1); i *= 2)
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++)
			{
				if (map[j] & i) cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ret = min(sum, ret);
		return;
	}

	go(here + 1);
	map[here] = ~map[here];
	go(here + 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int val = 1;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'T') map[i] |= val;
			val *= 2;
		}
	}

	go(1);
	cout << ret << "\n";
	return 0;
}