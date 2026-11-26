#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> arr;

bool go(int mid)
{
	int cnt = 1, sum = 0;

	for (int i = 0; i < n; i++)
	{
		if (sum + arr[i] > mid)
		{
			cnt++;
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
	}

	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int left = 0, right = 0, ret = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		left = max(left, arr[i]);
		right += arr[i];
	}

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (go(mid))
		{
			ret = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	vector<int> groups;
	int sum = 0, len = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + arr[i] > ret)
		{
			groups.push_back(len);
			sum = arr[i];
			len = 1;
		}
		else
		{
			sum += arr[i];
			len++;
		}
	}
	groups.push_back(len);

	int need = m - (int)groups.size();
	vector<int> ans;
	ans.reserve(m);

	for (int sz : groups)
	{
		while (sz > 1 && need > 0)
		{
			ans.push_back(1);
			sz--;
			need--;
		}
		ans.push_back(sz);
	}

	cout << ret << "\n";
	for (const int i : ans)
	{
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}