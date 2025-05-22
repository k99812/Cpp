#include<iostream>
#include<algorithm>
#include<vector>

#define MOD 1000000007

using namespace std;

int n, m, k;
vector<int> v, segTree;

int init(int node, int start, int end)
{
	if (start == end)
	{
		return segTree[node] = v[start];
	}

	int mid = (start + end) / 2;
	return segTree[node] = (1LL * init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end)) % MOD;
}

void update(int node, int start, int end, int idx, int val)
{
	if (idx < start || end < idx) return;

	if (start == end)
	{
		segTree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, val);
	update(2 * node + 1, mid + 1, end, idx, val);
	segTree[node] = (1LL * segTree[2 * node] * segTree[2 * node + 1]) % MOD;
}

int query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return 1;

	if (left <= start && end <= right) return segTree[node];

	int mid = (start + end) / 2;
	return (1LL * query(2 * node, start, mid, left, right) * query(2 * node + 1, mid + 1, end, left, right)) % MOD;
}

int main()
{
	cin >> n >> m >> k;

	v = vector<int>(n + 1);
	segTree = vector<int>(4 * n);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	init(1, 1, n);

	int cnt = m + k;
	while (cnt--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else
		{
			cout << query(1, 1, n, b, c) << "\n";
		}
	}

	return 0;
}