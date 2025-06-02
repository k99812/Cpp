#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, len;
vector<pair<int, int>> v;
vector<int> lis;

int main()
{
	cin >> n;

	v = vector<pair<int, int>>(n);
	lis = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	return 0;
}