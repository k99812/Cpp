#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;

int main()
{
	cin >> T;

	while (T--)
	{
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> v(n * 2);

		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			v[i + n] = v[i];
		}

		int ret = 0, first = 0, second = 0, sum = 0;

		for (int i = 0; i < m; i++)
		{
			sum += v[i];
			second++;
		}

		if (n == m)
		{
			cout << (sum < k ? 1 : 0) << "\n";
			continue;
		}

		while (true)
		{
			if (sum < k)
			{
				ret++;
			}

			if (second - first >= m)
			{
				sum -= v[first];
				first++;
			}

			if (first >= n) break;

			while (second - first < m)
			{
				sum += v[second];
				second++;
			}
		}

		cout << ret << "\n";
	}

	return 0;
}