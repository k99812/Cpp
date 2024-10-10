#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int a, b, temp, cnt;
map<int, int> m;

int main()
{
	cin >> a >> b;

	for (int i = 0; i < a; i++)
	{
		cin >> temp;
		m[temp]++;
	}

	for (int i = 0; i < b; i++)
	{
		cin >> temp;
		m[temp]++;
	}

	for (pair<int, int> i : m)
	{
		if (i.second == 1) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}