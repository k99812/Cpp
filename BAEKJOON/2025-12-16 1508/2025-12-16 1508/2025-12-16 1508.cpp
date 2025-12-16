#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m, k;

vector<int> arr;

bool check(int mid)
{
	int cnt = 1;
	int prev = arr[0];
	
	for (int i = 1; i < k; i++)
	{
		if (arr[i] - prev >= mid)
		{
			prev = arr[i];
			cnt++;
		}
	}

	return cnt >= m;
}

int main()
{
	cin >> n >> m >> k;

	arr = vector<int>(k);

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int left = 1, right = n;
	int dist = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (check(mid))
		{
			dist = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	string ret = "1";
	int cnt = 1;
	int prev = arr[0];

	for (int i = 1; i < k; i++)
	{
		if (cnt == m)
		{
			ret += "0";
			continue;
		}

		if (arr[i] - prev >= dist)
		{
			ret += "1";
			cnt++;
			prev = arr[i];
		}
		else
		{
			ret += "0";
		}
	}

	cout << ret << "\n";

	return 0;
}