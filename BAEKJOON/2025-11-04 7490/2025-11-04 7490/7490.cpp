#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int t, n;

int go(const string& str)
{
	string cal = "";

	for (const char& c : str)
	{
		if (c != ' ') cal += c;
	}

	int sum = 0, now = 0, sign = 1;

	for (const char& c : cal)
	{
		if (isdigit(c))
		{
			now = now * 10 + (c - '0');
		}
		else
		{
			sum += now * sign;

			now = 0;
			sign = c == '+' ? 1 : -1;
		}
	}

	sum += now * sign;

	return sum; 
}

void dfs(int now, string str)
{
	if (now > n)
	{
		if (go(str) == 0)
		{
			cout << str << "\n";
		}

		return;
	}

	dfs(now + 1, str + " " + to_string(now));
	dfs(now + 1, str + "+" + to_string(now));
	dfs(now + 1, str + "-" + to_string(now));
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;
		dfs(2, "1");
		cout << "\n";
	}

	return 0;
}