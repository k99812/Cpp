#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, to, from, ret;
vector<pair<int, int>> v;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> from >> to;
		v.push_back({ to, from });
	}

	sort(v.begin(), v.end());

	to = v[0].first;
	from = v[0].second;
	ret++;

	for (int i = 1; i < n; i++)
	{
		if (v[i].second < to) continue;
		from = v[i].second; to = v[i].first;
		ret++;
	}

	cout << ret << "\n";
	return 0;
}