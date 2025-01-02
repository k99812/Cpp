#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	long long ret = 0;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			int sum = v[i] + v[j];
			int first = upper_bound(v.begin() + (j + 1), v.end(), -sum) - v.begin();
			int second = lower_bound(v.begin() + (j + 1), v.end(), -sum) - v.begin();
			ret += first - second;
		}
	}

	cout << ret << "\n";

	return 0;
}