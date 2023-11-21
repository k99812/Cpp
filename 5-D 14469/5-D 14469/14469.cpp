#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, a, b, start, last;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back({ a, b });
	}

	sort(v.begin(), v.end());

	start = v[0].first;
	last = start + v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first > last)
		{
			start = v[i].first;
			last = start + v[i].second;
		}
		else if (v[i].first <= last)
		{
			start = last;
			last = start + v[i].second;
		}
	}

	cout << last << "\n";

	return 0;
}