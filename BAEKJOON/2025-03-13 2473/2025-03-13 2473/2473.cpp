#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;

int main()
{
	cin >> n;

	vector<ll> v(n);

	for (ll& i : v)
	{
		cin >> i;
	}

	sort(v.begin(), v.end());

	ll num = 1e18;
	ll ret1, ret2, ret3;

	for (int i = 0; i < n - 2; i++)
	{
		int left = i + 1;
		int right = n - 1;

		while (left < right)
		{
			ll sum = v[i] + v[left] + v[right];

			if (abs(sum) < abs(num))
			{
				num = sum;
				ret1 = v[i];
				ret2 = v[left];
				ret3 = v[right];
			}

			if (sum < 0)
			{
				++left;
			}
			else
			{
				--right;
			}
		}
	}

	cout << ret1 << " " << ret2 << " " << ret3 << "\n";

	return 0;
}