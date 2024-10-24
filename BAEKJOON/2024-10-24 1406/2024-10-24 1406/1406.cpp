#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<map>

using namespace std;

int n;
string s;
map<string, int> table;

void init_map()
{
	table["L"] = 1;
	table["D"] = 2;
	table["B"] = 3;
	table["P"] = 4;
}

int main()
{
	init_map();
	cin >> s >> n;
	list<char> ret;

	for (char c : s) ret.push_back(c);

	list<char>::iterator cursor = ret.end();

	while (n--)
	{
		string commend;
		cin >> commend;

		switch (table[commend])
		{
		case 1:
			if (cursor != ret.begin()) cursor--;
			break;
		case 2:
			if (cursor != ret.end())  cursor++;
			break;
		case 3:
			if (cursor != ret.begin())
			{
				cursor--;
				cursor = ret.erase(cursor);
			}
			break;
		case 4:
			char temp;
			cin >> temp;
			ret.insert(cursor, temp);
			break;
		}
	}

	for (char c : ret) cout << c;
	cout << "\n";

	return 0;
}