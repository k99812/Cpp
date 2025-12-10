#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

ll l;
int k, c;
vector<int> arr;

pair<bool, int> go(const ll& mid)
{
	int cnt = 0, prev = l, first = 0;

	for (int i = arr.size() - 2; i >= 0; i--)
	{
		int dist = prev - arr[i];

		if (dist > mid)
		{
			if (arr[i + 1] - arr[i] > mid) return { false, 0 };

			if (prev - arr[i] > mid)
			{
				cnt++;
				prev = arr[i + 1];
				first = arr[i + 1];
			}
		}
	}

	if (prev > mid || cnt > c) return { false, 0 };

	if (cnt < c) first = arr[1];

	return { true, first };
}

int main()
{
	cin >> l >> k >> c;

	arr = vector<int>(k);

	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	arr.push_back(0);
	arr.push_back(l);
	sort(arr.begin(), arr.end());

	ll left = 0, right = l;
	int len = -1, min_idx = -1;
	while (left <= right)
	{
		ll mid = (left + right) / 2;

		pair<bool, int> ret = go(mid);
		bool check = ret.first;
		int idx = ret.second;

		if (check)
		{
			len = mid, min_idx = idx;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	cout << len << " " << min_idx << "\n";

	return 0;
}