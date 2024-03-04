#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, a[1004], len, ret, dp[1004], dp2[1004];
vector<int> lis(1004), r_lis(1004);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		vector<int>::iterator itr = lower_bound(lis.begin(), lis.begin() + len, a[i]);
		int pos = itr - lis.begin();
		if (lis[pos] == 0) len++;
		lis[pos] = a[i];
		dp[i] = pos;
	}

	len = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		vector<int>::iterator itr2 = lower_bound(r_lis.begin(), r_lis.begin() + len, a[i]);
		int pos = itr2 - r_lis.begin();
		if (r_lis[pos] == 0) len++;
		r_lis[pos] = a[i];
		dp2[i] = pos;
	}
	
	for (int i = 0; i < n; i++)
	{
		ret = max(ret, dp[i] + dp2[i]);
	}

	cout << ret + 1 << "\n";

	return 0;
}