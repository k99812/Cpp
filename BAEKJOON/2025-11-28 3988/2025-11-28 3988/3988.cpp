#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int INF = 2e9;

int n, k;
vector<int> arr, diff;

int main()
{
	cin >> n >> k;

	arr = vector<int>(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < n - 1; i++)
	{
		diff.push_back(arr[i + 1] - arr[i]);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int window = n - k, ret = INF;
	int idx = window - 1;

	for (int i = 0; i <= k; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < idx; j++)
			{
				pq.push({ diff[j], j });
			}
		}
		else
		{
			int next_idx = i + idx - 1;
			if (next_idx < diff.size())
			{
				pq.push({ diff[next_idx], next_idx });
			}
		}

		while (pq.size() && pq.top().second < i)
		{
			pq.pop();
		}

		int ans = (arr[i + window - 1] - arr[i]) + pq.top().first;
		ret = min(ret, ans);
	}

	cout << ret << "\n";

	return 0;
}