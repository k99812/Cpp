#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define max_n 200004
typedef long long ll;

const ll mod = 1e9 + 7;
int n, value;
ll ret = 1;
vector<ll> tree_cnt(max_n), tree_sum(max_n);

ll sum(vector<ll>& tree, int value)
{
	ll r = 0;

	while (value)
	{
		r += tree[value];
		value -= (value & -value);
	}
	return r;
}

void update(vector<ll>& tree, int idx, ll value)
{
	while (idx <= max_n)
	{
		tree[idx] += value;
		idx += (idx & -idx);
	}
	return;
}

ll re_sum(vector<ll>& tree, int s, int e)
{
	if (s > e) return 0;
	return (sum(tree, e) - sum(tree, s - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> value; value++;

		if (i != 1)
		{
			ll left = value * re_sum(tree_cnt, 1, value - 1) - re_sum(tree_sum, 1, value - 1);
			ll right = re_sum(tree_sum, value + 1, max_n) - value * re_sum(tree_cnt, value + 1, max_n);
			ret *= (left + right) % mod;
			ret %= mod;
		}
		update(tree_cnt, value, 1);
		update(tree_sum, value, value);
	}

	cout << ret << "\n";

	return 0;
}