#include<iostream>
#include<algorithm>

#define MAX_NUM 15 + 5

using namespace std;

int n;
pair<int, int> a[MAX_NUM];

int go(int idx)
{
	if (idx > n)
	{
		return -1e9;
	}
	if (idx == n)
	{
		if (a[idx].first == 1)
		{
			return a[idx].second;
		}

		return 0;
	}

	int ret = 0;

	ret = max(ret, go(idx + 1));
	ret = max(ret, go(idx + a[idx].first) + a[idx].second);

	return ret;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}

	cout << go(0) << "\n";

	return 0;
}