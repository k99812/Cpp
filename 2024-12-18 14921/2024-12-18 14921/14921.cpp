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

	int left = 0, right = n - 1, ret = 2e9;
	pair<int, int> a;
	while (left < right)
	{
		int sum = v[left] + v[right];

		if (abs(sum) < ret)
		{
			ret = abs(sum);
			a = { left, right };
		}

		if (sum <= 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << v[a.first] + v[a.second] << "\n";

	return 0;
}