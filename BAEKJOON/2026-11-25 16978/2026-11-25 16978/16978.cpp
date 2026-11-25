#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n, m;

struct SegTree
{
	vector<ll> tree;

	SegTree() {}
	SegTree(int n)
	{
		tree.assign(4 * n + 1, 0);
	}

	ll init(int node, int l, int r, const vector<int>& arr)
	{
		if (l == r)
		{
			return tree[node] = arr[l];
		}

		int mid = l + (r - l) / 2;
		return tree[node] = init(2 * node, l, mid, arr) + init(2 * node + 1, mid + 1, r, arr);
	}

	ll update(int node, int l, int r, int idx, int val)
	{
		if (idx < l || r < idx) return tree[node];

		if (idx == l && r == idx)
		{
			return tree[node] = val;
		}

		int mid = l + (r - l) / 2;
		return tree[node] = update(2 * node, l, mid, idx, val) + update(2 * node + 1, mid + 1, r, idx, val);
	}

	ll query(int node, int l, int r, int lq, int rq)
	{
		if (r < lq || rq < l) return 0;

		if (lq <= l && r <= rq)
		{
			return tree[node];
		}

		int mid = l + (r - l) / 2;
		return query(2 * node, l, mid, lq, rq) + query(2 * node + 1, mid + 1, r, lq, rq);
	}
};

struct update
{
	int idx, val;
};

struct query
{
	int k, l, r, id;

	bool operator<(const query& other) const
	{
		return k < other.k;
	}
};

int main()
{
	cin >> n;
	vector<int> arr(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	SegTree tree(n);
	tree.init(1, 1, n, arr);
	
	cin >> m;
	vector<update> up;
	vector<query> qu;
	up.reserve(m);
	qu.reserve(m);

	for (int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		
		if (type == 1)
		{
			int idx, val;
			cin >> idx >> val;

			up.push_back({ idx, val });
		}
		else
		{
			int k, l, r;
			cin >> k >> l >> r;

			qu.push_back({ k, l, r, (int)qu.size() });
		}
	}

	sort(qu.begin(), qu.end());

	vector<ll> ret(qu.size());
	int cnt = 0;

	for (const auto& [k, l, r, id] : qu)
	{
		while (cnt < up.size() && cnt < k)
		{
			const auto& [idx, val] = up[cnt];
			tree.update(1, 1, n, idx, val);
			cnt++;
		}

		if (cnt < k) break;

		ret[id] = tree.query(1, 1, n, l, r);
	}

	for (ll x : ret)
	{
		cout << x << "\n";
	}

	return 0;
}