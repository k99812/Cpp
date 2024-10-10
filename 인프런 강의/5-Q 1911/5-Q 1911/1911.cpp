#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, l, ret, idx, num;

int main()
{
	cin >> n >> l;
	vector<pair<int, int>> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		if (a[i].second <= idx) continue;
		else if (idx < a[i].first)
		{
			num = (a[i].second - a[i].first) / l + ((a[i].second - a[i].first) % l ? 1 : 0);
			idx = a[i].first + num * l;
		}
		else
		{
			num = (a[i].second - idx) / l + ((a[i].second - idx) % l ? 1 : 0);
			idx = idx + num * l;
		}
		ret += num;
	}

	cout << ret << "\n";

	return 0;
}