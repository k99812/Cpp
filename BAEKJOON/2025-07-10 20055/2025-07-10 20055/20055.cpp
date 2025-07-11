#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, k;
vector<pair<int, int>> v;

int go()
{
	int step = 0, broken = 0;
	while (broken < k)
	{
		rotate(v.begin(), v.end() - 1, v.end());
		v[n - 1].second = false;

		for (int i = n - 2; i >= 0; i--)
		{
			if (v[i].second && !v[i + 1].second && v[i + 1].first > 0)
			{
				v[i].second = false;
				v[i + 1].second = true;
				if (--v[i + 1].first == 0) ++broken;
			}
		}
		v[n - 1].second = false;

		if (v[0].first > 0 && !v[0].second)
		{
			if (--v[0].first == 0) ++broken;
			v[0].second = true;
		}

		++step;
	}

	return step;
}

int main()
{
	cin >> n >> k;

	v = vector<pair<int, int>>(2 * n);

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> v[i].first;
	}

	cout << go() << "\n";

	return 0;
}