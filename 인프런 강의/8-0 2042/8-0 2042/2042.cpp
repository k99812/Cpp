#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
int n, m, k, a, b, c;
ll c2;

ll sum(vector<ll>& tree, int i)
{
	ll ans = 0;

	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<ll>& tree, int i, ll diff)
{
	while (i < tree.size())
	{
		tree[i] += diff;
		i += (i & -i);
	}
}

int main()
{
	cin >> n >> m >> k;
	vector<ll> v(n + 1);
	vector<ll> tree(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
		update(tree, i, v[i]);
	}

	int cnt = m + k;

	while (cnt--)
	{
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c2;

			ll diff = c2 - v[b];
			v[b] = c2;

			update(tree, b, diff);
		}
		else
		{
			cin >> b >> c;

			cout << sum(tree, c) - sum(tree, b - 1) << "\n";
		}

	}

	return 0;
}