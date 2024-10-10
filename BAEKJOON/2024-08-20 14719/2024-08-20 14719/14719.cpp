#include<iostream>
#include<algorithm>
#include<vector>

#define MAX_NUM 500 + 4

using namespace std;

int n, m, a[MAX_NUM];
vector<pair<int, int>> v;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}

	int left = 0;
	for (int i = 1; i < m; i++)
	{
		if (a[left] <= a[i])
		{
			v.push_back({ left, i });
			left = i;
		}
	}

	int right = m - 1;
	for (int i = m - 1; i >= 0; i--)
	{
		if (a[right] < a[i])
		{
			v.push_back({ i, right });
			right = i;
		}
	}

	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int MIN = min(a[v[i].first], a[v[i].second]);
		for (int j = v[i].first + 1; j < v[i].second; j++)
		{
			ret += MIN - a[j];
		}
	}

	cout << ret << "\n";

	return 0;
}