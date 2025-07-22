#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, b, c;
vector<int> nums;

int main()
{
	cin >> n;

	nums = vector<int>(n);

	for (int& i : nums)
	{
		cin >> i;
	}

	cin >> b >> c;

	long long ret = 0;
	for (const int& num : nums)
	{
		long long temp = num - b;
		ret++;

		if (temp > 0)
		{
			ret += temp / c;
			if (temp % c != 0) ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}