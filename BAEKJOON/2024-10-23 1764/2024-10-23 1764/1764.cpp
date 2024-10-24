#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int n, m;
vector<string> noListen, noSee;
map<string, int> table;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		noListen.push_back(s);
		table[s]++;
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (table[s]) noSee.push_back(s);
	}

	sort(noSee.begin(), noSee.end());

	cout << noSee.size() << "\n";
	for (string str : noSee)
	{
		cout << str << "\n";
	}

	return 0;
}