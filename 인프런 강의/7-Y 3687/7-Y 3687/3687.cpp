#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, t, a[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[104], MAX_STR = "11111111111111111111111111111111111111111111111111111";

string GetMinStr(string a, string b)
{
	if (a.size() == b.size()) return a < b ? a : b;
	if (a.size() < b.size()) return a;
	return b;
}

string findMax(int num)
{
	string ret = "";
	if (num & 1)
	{
		ret += '7';
		num -= 3;
	}

	while (num)
	{
		ret += '1';
		num -= 2;
	}
	return ret;
}

string findMin(int num)
{
	if (num == 0) return "";

	string& ret = dp[num];
	if (ret != MAX_STR) return ret;

	for (int i = 0; i < 10; i++)
	{
		if (num - a[i] < 0) continue;
		if (num == t && i == 0) continue;

		ret = GetMinStr(ret, to_string(i) + findMin(num - a[i]));
	}

	return ret;
}

int main()
{
	cin >> n;

	while (n--)
	{
		cin >> t; 

		fill(&dp[0], &dp[104], MAX_STR);
		cout << findMin(t) << " " << findMax(t) << "\n";
	}

	return 0;
}