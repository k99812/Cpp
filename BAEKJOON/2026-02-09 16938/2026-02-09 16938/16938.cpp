#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, l, r, x, ret = 0;
vector<int> arr, selected;

void dfs(int idx, int size, int minLevel, int maxLevel, int total)
{
	if (size >= 2)
	{
		if (total >= l && total <= r && (maxLevel - minLevel) >= x)
		{
			ret++;
		}
	}

	for (int i = idx; i < n; i++)
	{
		selected[i] = true;
		dfs(i + 1, size + 1, min(minLevel, arr[i]), max(maxLevel, arr[i]), total + arr[i]);
		selected[i] = false;
	}
}

int main()
{
	cin >> n >> l >> r >> x;

	arr.assign(n, 0);
	selected.assign(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	dfs(0, 0, 1e9, -1, 0);

	cout << ret << "\n";

	return 0;
}