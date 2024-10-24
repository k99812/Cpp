#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n;
map<string, string, greater<string>> table;


int main()
{
	cin >> n;

	while (n--)
	{
		string name, log;
		cin >> name >> log;

		table[name] = log;
	}

	for (const pair<string, string>& str : table)
	{
		if (str.second == "enter") cout << str.first << "\n";
	}

	return 0;
}