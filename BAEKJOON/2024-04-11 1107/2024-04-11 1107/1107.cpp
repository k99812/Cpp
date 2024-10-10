#include<iostream>
#include<algorithm>
#include<string>

#define INF 1e9

using namespace std;

int n, m, buttons[14], now = 100, ret, temp;

bool isBroken(int n)
{
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++)
	{
		if (buttons[s[i] - '0'])
		{
			return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		buttons[temp]++;
	}

	if (n == 100)
	{
		cout << 0 << "\n";
		return 0;
	}

	ret = abs(100 - n);

	for (int i = 0; i <= 1000000; i++)
	{
		if (!isBroken(i))
		{
			ret = min(ret, (int)(abs(n - i) + to_string(i).size()));
		}
	}

	cout << ret << "\n";

	return 0;
}