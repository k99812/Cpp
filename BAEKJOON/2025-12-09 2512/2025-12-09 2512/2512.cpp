#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
ll m;
vector<int> arr;

bool check(const ll& num)
{
	ll sum = 0;

	for (const int& i : arr)
	{
		ll next = min(1LL * i, num);
		sum += next;
	}

	return sum <= m;
}

int main()
{
	cin >> n;

	arr = vector<int>(n);

	ll sum = 0;
	int max_num = -1;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];

		max_num = max(max_num, arr[i]);
		sum += arr[i];
	}

	cin >> m;

	if (sum <= m)
	{
		cout << max_num << "\n";
		return 0;
	}

	ll left = 1, right = max_num, ret = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		if (check(mid))
		{
			ret = max(ret, mid);
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ret << "\n";

	return 0;
}