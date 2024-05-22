#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m, k, ret = -1;
vector<string> v;
string s;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);
	}

	cin >> k;

	for (int i=0; i<n; i++)
	{
		int zeroCnt = 0;
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == '0') zeroCnt++;
		}

		int sum = 0;
		if (zeroCnt <= k && zeroCnt % 2 == k % 2)
		{
			for (int j = 0; j < n; j++)
			{
				if (v[i] == v[j]) sum++;
			}
		}

		ret = max(ret, sum);
	}

	cout << ret << "\n";

	return 0;
}