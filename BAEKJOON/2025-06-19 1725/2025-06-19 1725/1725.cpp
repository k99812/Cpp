#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
ll ret = INT64_MIN;
vector<ll> arr;
vector<pair<ll, int>> segTree;

pair<ll, int> init(int node, int start, int end)
{
	if (start == end)
	{
		return segTree[node] = { arr[start], start };
	}

	int mid = (start + end) / 2;
	return segTree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

void update(int node, int start, int end, int idx, ll val)
{
	if (idx < start || end < idx) return;

	if (start == end)
	{
		segTree[node] = { val, idx };
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, val);
	update(2 * node + 1, mid + 1, end, idx, val);
	segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

pair<ll, int> query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return { INT64_MAX, INT64_MAX };

	if (left <= start && end <= right)
	{
		return segTree[node];
	}

	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
}

void go(int start, int end)
{
	if (start > end) return;

	pair<ll, int> p = query(1, 0, n - 1, start, end);
	ll height = p.first; int idx = p.second;
	ret = max(ret, height * (end - start + 1));

	go(start, idx - 1);
	go(idx + 1, end);
}

int main()
{
	cin >> n;

	arr = vector<ll>(n);
	segTree = vector<pair<ll, int>>(4 * n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	init(1, 0, n - 1);
	go(0, n - 1);

	cout << ret << "\n";

	return 0;
}