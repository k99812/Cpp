#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, x, y;
vector<pair<int, int>> v;

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back({ x, y });
		}

	}

	return 0;
}