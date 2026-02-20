#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<regex>

using namespace std;

int n;

int main()
{
	cin >> n;

	regex pattern("(100+1+|01)+");

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		if (regex_match(s, pattern))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}