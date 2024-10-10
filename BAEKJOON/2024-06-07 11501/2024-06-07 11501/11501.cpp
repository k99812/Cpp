#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, n, temp;

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> n;
		vector<int> v(n);

		int max_num = 0;
		long long ret = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		for (int i = n - 1; i >= 0; i--)
		{
			max_num = max(max_num, v[i]);
			ret += max_num - v[i];
		}

		cout << ret << "\n";
	}

	return 0;
}