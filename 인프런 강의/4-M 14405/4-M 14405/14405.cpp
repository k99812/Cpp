#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string s;
bool canSay = true;

int main()
{
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		if (i < s.length() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") i += 1;
		else if (i < s.length() - 2 && s.substr(i, 3) == "chu") i += 2;
		else canSay = false;
	}
	canSay ? cout << "YES\n" : cout << "NO\n";
	return 0;
}