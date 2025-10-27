#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, k;

int main()
{
	cin >> n >> k;

	ll low = 1, high = 1LL * n * n, ret = 0;
	while (low <= high)
	{
		ll mid = (low + high) / 2, nums = 0;

		for (int i = 1; i <= n; i++)
		{
			nums += min(1LL * n, mid / i);
		}

		if (nums >= k)
		{
			ret = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	cout << ret << "\n";

	return 0;
}