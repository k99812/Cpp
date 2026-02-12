#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> arr;

bool search(int mid)
{
	int min_num = arr[0], max_num = arr[0], cnt = 1;
	for (int i = 1; i < n; i++)
	{
		min_num = min(min_num, arr[i]);
		max_num = max(max_num, arr[i]);
		if (max_num - min_num > mid)
		{
			cnt++;
			min_num = arr[i], max_num = arr[i];
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

	int left = 0, right = 10000, ret = 1e9;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (search(mid))
		{
			right = mid - 1;
			ret = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}