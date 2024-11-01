#include<iostream>
#include<algorithm>

#define MAX_NUM 100000 + 4

using namespace std;

int n, a[MAX_NUM];
pair<int, int> ret;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int left = 0, right = n - 1, minNum = 2e9;

	while (left < right)
	{
		int sum = a[left] + a[right];
		if (minNum > abs(sum))
		{
			ret = { a[left], a[right] };
			minNum = abs(sum);
		}

		if (sum < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << ret.first << " " << ret.second << "\n";

	return 0;
}