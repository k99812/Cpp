#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e8;
int n, a[24][24], ret = INF;

int go(vector<int>& t1, vector<int>& t2)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n / 2; j++)
		{
			if (i == j) continue;
			sum1 += a[t1[i]][t1[j]];
			sum2 += a[t2[i]][t2[j]];
		}
	}
	return abs(sum1 - sum2);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++)
	{
		if (__builtin_popcount(i) != n / 2) continue;
		vector<int> v1, v2;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) v1.push_back(j);
			else v2.push_back(j);
		}
		ret = min(ret, go(v1, v2));
	}

	cout << ret << "\n";

	return 0;
}