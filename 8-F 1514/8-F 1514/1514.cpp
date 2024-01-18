#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, now[104], pass[104];
string s, s2;

int main()
{
	cin >> n >> s >> s2;

	for (int i = 0; i < n; i++)
	{
		now[i] = s[i] - '0';
		pass[i] = s2[i] - '0';
	}

	return 0;
}