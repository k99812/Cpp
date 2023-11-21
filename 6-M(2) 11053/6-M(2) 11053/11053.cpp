#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, ret;

int main()
{
	cin >> n;
	vector<int> a(n), cnt(n);

	fill(cnt.begin(), cnt.end(), 1);

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && cnt[i] < cnt[j] + 1)
			{
				cnt[i] = cnt[j] + 1;
			}
			ret = max(ret, cnt[i]);
		}
	}

	cout << ret << "\n";

	return 0;
}