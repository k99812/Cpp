#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX_POS = 1000000;

int n, k;
vector<int> arr;

int main()
{
	cin >> n >> k;

	arr.assign(MAX_POS + 4, 0);

	int max_r = 0;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		max_r = max(max_r, r);

		arr[l]++;
		arr[r]--;
	}

	for (int i = 1; i <= max_r; i++)
	{
		arr[i] += arr[i - 1];
	}

	int left = 0, right = 0;
	long long sum = 0;

	while (right <= max_r || sum >= k)
	{
		if (sum == k)
		{
			cout << left << " " << right << "\n";
			return 0;
		}
		else if (sum < k)
		{
			sum += arr[right];
			right++;
		}
		else
		{
			sum -= arr[left];
			left++;
		}
	}

	cout << 0 << " " << 0 << "\n";

	return 0;
}