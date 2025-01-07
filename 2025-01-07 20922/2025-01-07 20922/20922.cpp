#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	map<int, int> nums;
	int first = 0, second = 0, ret = 0;

	while (second < n)
	{
		while (second < n)
		{
			if (nums[v[second]] == k) break;
			nums[v[second++]]++;
		}

		ret = max(ret, second - first);

		if (second < n  && nums[v[second]] == k)
		{
			nums[v[first++]]--;
		}
	}

	cout << ret << "\n";

	return 0;
}