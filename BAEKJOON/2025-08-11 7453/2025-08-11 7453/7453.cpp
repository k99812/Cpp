#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> a, b, c, d;

int main()
{
	cin >> n;

	a = b = c = d = vector<int>(n);

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	vector<int> ab_sum(n * n), cd_sum(n * n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab_sum[i * n + j] = a[i] + b[j];
			cd_sum[i * n + j] = c[i] + d[j];
		}
	}

	sort(ab_sum.begin(), ab_sum.end());
	sort(cd_sum.begin(), cd_sum.end());

	long long ret = 0;
	int left = 0, right = cd_sum.size() - 1;

	while (left < ab_sum.size() && right >= 0)
	{
		int mid = ab_sum[left] + cd_sum[right];
		if (mid == 0)
		{
			int ab = ab_sum[left], cd = cd_sum[right];
			long long ab_cnt = 0, cd_cnt = 0;

			while (left < ab_sum.size() && ab == ab_sum[left])
			{
				ab_cnt++, left++;
			}

			while (right >= 0 && cd == cd_sum[right])
			{
				cd_cnt++, right--;
			}

			ret += ab_cnt * cd_cnt;
		}
		else if (mid < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << ret << "\n";

	return 0;
}