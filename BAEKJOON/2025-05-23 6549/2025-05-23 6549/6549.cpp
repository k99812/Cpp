#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

int n;
vector<ll> v;
vector<int> segTree;

int init(int node, int start, int end)
{
	if (start == end)
	{
		return segTree[node] = start;
	}

	int mid = (start + end) / 2;
	int left = init(2 * node, start, mid);
	int right = init(2 * node + 1, mid + 1, end);
	return segTree[node] = v[left] <= v[right] ? left : right;
}

int query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return INT32_MAX;

	if (left <= start && end <= right) return segTree[node];

	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
}

ll getArea(int start, int end)
{
	if (end < start) return 0;

	int minIdx = query(1, 1, n, start, end);
	ll area = v[minIdx] * (end - start);

	ll leftArea = getArea(start, minIdx - 1);
	ll rightArea = getArea(minIdx + 1, end);

	return max({ area, leftArea, rightArea });
}

int main()
{
	while (cin >> n && n != 0)
	{
		v = vector<ll>(n + 1);
		segTree = vector<int>(4 * n);

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}

		init(1, 1, n);

		cout << getArea(1, n) << "\n";
	}

	return 0;
}