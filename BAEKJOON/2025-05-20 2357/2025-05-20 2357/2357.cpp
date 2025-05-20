#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<int> v;
vector<pair<int, int>> segTree;

pair<int, int> init(int node, int start, int end)
{
	if (start == end)
	{
		return segTree[node] = { v[start], v[start] };
	}

	int mid = (start + end) / 2;
	pair<int, int> left = init(2 * node, start, mid);
	pair<int, int> right = init(2 * node + 1, mid + 1, end);
	return segTree[node] = { min(left.first, right.first), max(left.second, right.second) };
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return { INT32_MAX, 0 };

	if (left <= start && end <= right) return segTree[node];

	int mid = (start + end) / 2;
	pair<int, int> leftTree = query(2 * node, start, mid, left, right);
	pair<int, int> rightTree= query(2 * node + 1, mid + 1, end, left, right);
	return { min(leftTree.first, rightTree.first), max(leftTree.second, rightTree.second)};
}

int main()
{
	cin >> n >> m;

	v = vector<int>(n + 1);
	segTree = vector<pair<int, int>>(4 * n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	init(1, 1, n);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		pair<int, int> ret = query(1, 1, n, a, b);
		cout << ret.first << " " << ret.second << "\n";
	}

	return 0;
}