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
		return segTree[node] = { v[start], start };
	}

	int mid = (start + end) / 2;
	return segTree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
}

void update(int node, int start, int end, int idx, int val)
{
	if (idx < start || end < idx) return;

	if (start == end) 
	{
		segTree[node] = { val, start };
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, val);
	update(2 * node + 1, mid + 1, end, idx, val);
	segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return { INT32_MAX, INT32_MAX };

	if (left <= start && end <= right) return segTree[node];

	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
}

int main()
{
	cin >> n;
	v = vector<int>(n + 1);
	segTree = vector<pair<int, int>>(4 * n);

	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	init(1, 1, n);

	cin >> m;

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			update(1, 1, n, b, c);
		}
		else
		{
			cout << query(1, 1, n, b, c).second << "\n";
		}
	}

	return 0;
}