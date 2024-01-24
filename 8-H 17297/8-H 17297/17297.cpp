#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int max_n = 39;
int m, dp[max_n + 1] = { 0, 5, 13 };
string s = "Messi Gimossi";

int main()
{
	cin >> m;
	m--;

	for (int i = 3; i <= max_n; i++)
	{
		dp[i] = dp[i - 1] + 1 + dp[i - 2];
	}

	for (int i = max_n; i >= 2; i--)
	{
		if (m >= dp[i]) m -= (dp[i] + 1);
	}

	if (m == 5 || m == -1) cout << "Messi Messi Gimossi" << "\n";
	else cout << s[m] << "\n";

	return 0;
}