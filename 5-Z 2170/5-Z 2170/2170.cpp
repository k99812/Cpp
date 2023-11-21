#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, x, y, ret, l, r;
vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}

	sort(v.begin(), v.end());

	l = v[0].first, r = v[0].second;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first <= r && v[i].second >= r)
		{
			r = v[i].second;
		}
		else if (v[i].first > r)
		{
			ret += r - l;
			l = v[i].first, r = v[i].second;
		}
	}
	ret += r - l;
	cout << ret << "\n";

	return 0;
}