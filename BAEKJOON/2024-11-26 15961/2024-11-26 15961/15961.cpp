#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int n, d, k, c;

int main()
{
	cin >> n >> d >> k >> c;

	vector<int> v(n);
	map<int, int> m;

	m[c] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int first = 0, second = 0, ret = 0, cnt = 1;
	while (first < n)
	{
		if (second - first >= k)
		{
			if (!--m[v[first]])
			{
				cnt--;
			}
			first++;
		}

		while (second - first < k)
		{
			if (!m[v[second % n]])
			{
				cnt++;
			}
			m[v[second % n]]++;
			second++;
		}

		ret = max(ret, cnt);
	}

	cout << ret << "\n";

	return 0;
}