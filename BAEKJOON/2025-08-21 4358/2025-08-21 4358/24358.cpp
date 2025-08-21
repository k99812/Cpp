#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main()
{
	string str;
	map<string, int> m;

	int total = 0;
	while (getline(cin, str) && !str.empty()) 
	{
		m[str]++;
		total++;
	}

	cout << fixed;
	cout.precision(4);

	for (const pair<string, int>& p : m)
	{
		double ratio = (double)p.second / total * 100;
		cout << p.first << " " << ratio << "\n";
	}

	return 0;
}