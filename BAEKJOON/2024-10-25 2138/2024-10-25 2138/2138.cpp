#include<iostream>
#include<algorithm>
#include<string>

#define MAX_NUM 100000 + 4
#define INF 1e9

using namespace std;

int n;
string s, t, temp;

void change(int idx)
{
	const int dx[] = { -1, 0, 1 };
	for (int i = 0; i < 3; i++)
	{
		int next = idx + dx[i];
		if (next < 0 || next >= n) continue;

		if (temp[next] == '0') temp[next] = '1';
		else temp[next] = '0';
	}
}

int go(bool state)
{
	int cnt = 0;
	temp = s;

	if (state)
	{
		change(0);
		cnt++;
	}

	for (int i = 1; i < n; i++)
	{
		if (temp[i - 1] != t[i - 1])
		{
			change(i);
			cnt++;
		}
	}

	if (temp != t)
	{
		return INF;
	}

	return cnt;
}

int main()
{
	cin >> n;
	cin >> s >> t;

	int ret = min(go(true), go(false));
	cout << (ret == INF ? -1 : ret) << "\n";

	return 0;
}