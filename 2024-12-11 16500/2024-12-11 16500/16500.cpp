#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int n;
string s;

int main()
{
	cin >> s >> n;
	vector<string> str(n + 1);
	vector<int> dp(s.size() + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}

	dp[s.size()] = 1;

	for (int i = s.length() - 1; i >= 0; i--)
	{
		for (int j = 0; j <= n; j++)
		{
			if (s.find(str[j], i) == i && dp[i + str[j].size()])
			{
				dp[i] = 1;
				break;
			}
		}
	}

	cout << dp[0] << "\n";

	return 0;
}