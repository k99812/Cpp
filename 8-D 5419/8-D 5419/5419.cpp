#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int t, n, x, y;
vector<pair<int, int>> v;
vector<int> tree, _y;

int sum(int idx)
{
	int ret = 0;

	while (idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}
	return ret;
}

void update(int idx, int num)
{
	while (idx <= n)
	{
		tree[idx] += num;
		idx += (idx & -idx);
	}
	return;
}

int find_index(int value)
{
	int low = 0, hi = _y.size() - 1;
	while (low <= hi)
	{
		int mid = (low + hi) / 2;
		if (value == _y[mid]) return mid;
		if (value < _y[mid])
		{
			hi = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
}

int main()
{
	cin >> t;

	while (t--)
	{
		cin >> n;

		v.clear(); _y.clear();
		tree.clear();
		tree.resize(n + 1);

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			v.push_back({ x, y * -1});
			_y.push_back(y * -1);
		}

		sort(v.begin(), v.end());
		sort(_y.begin(), _y.end());

		long long ret = 0;

		update(find_index(v[0].second) + 1, 1); 
		for (int i = 1; i < n; i++)
		{
			int idx = find_index(v[i].second) + 1;
			ret += 1LL * sum(idx);
			update(idx, 1);
		}
		cout << ret << "\n";
	}

	return 0;
}