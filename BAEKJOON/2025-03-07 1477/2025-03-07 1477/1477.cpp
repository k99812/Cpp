#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, l;

bool check(int mid, const vector<int>& v)
{
	int cnt = 0;
	for (int i = 0; i < v.size() - 1; i++)
	{
		int dist = v[i + 1] - v[i];
		cnt += dist / mid;
		if (!(dist % mid))
		{
			--cnt;
		}
	}

	return cnt <= m;
}

int main()
{
	cin >> n >> m >> l;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	v.push_back(0);
	v.push_back(l);

	sort(v.begin(), v.end());

	int low = 1, hight = l, ret = INT32_MAX;
	while (low <= hight)
	{
		int mid = (low + hight) / 2;
		if (check(mid, v))
		{
			hight = mid - 1;
			ret = min(ret, mid);
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}