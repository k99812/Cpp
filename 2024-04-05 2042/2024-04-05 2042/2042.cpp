#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
int n, m, k, a, b;

void update(vector<ll>& tree, int idx, ll num)
{
	while (idx < tree.size())
	{
		tree[idx] += num;

		idx += (-idx & idx);
	}
}

ll sum(vector<ll>& tree, int idx)
{
	ll ret = 0;

	while (idx > 0)
	{
		ret += tree[idx];

		idx -= (-idx & idx);
	}

	return ret;
}

int main()
{
	cin >> n >> m >> k;
	vector<ll> tree(n + 1);
	vector<ll> v(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		update(tree, i, v[i]);
	}

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b;

		if (a == 1)
		{
			ll c;
			cin >> c;

			ll diff = c - v[b];
			v[b] = c;

			update(tree, b, diff);
		}
		else
		{
			int c;
			cin >> c;
			cout << sum(tree, c) - sum(tree, b - 1) << "\n";
		}
	}

	return 0;
}