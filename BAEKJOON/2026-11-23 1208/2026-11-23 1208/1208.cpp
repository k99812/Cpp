#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, s;
vector<int> arr;

void dfs(int idx, int end, int sum, vector<int>& target)
{
	if (idx == end)
	{
		target.push_back(sum);
		return;
	}

	dfs(idx + 1, end, sum, target);
	dfs(idx + 1, end, sum + arr[idx], target);
}

int main()
{
	cin >> n >> s;
	arr.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int mid = n / 2;
	vector<int> l, r;
	l.reserve(1 << mid);
	r.reserve(1 << (n - mid));

	dfs(0, mid, 0, l);
	dfs(mid, n, 0, r);

	sort(r.begin(), r.end());

	ll ret = 0;
	for (int x : l)
	{
		int target = s - x;
		auto up = upper_bound(r.begin(), r.end(), target);
		auto low = lower_bound(r.begin(), r.end(), target);
		ret += up - low;
	}

	if (s == 0) ret--;

	cout << ret << "\n";

	return 0;
}