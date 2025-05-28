#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int n;
vector<int> A, segTree;
map<int, int> B;

void update(int node, int start, int end, int idx)
{
	if (idx < start || end < idx) return;

	if (start == end)
	{
		segTree[node] = 1;
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx);
	update(2 * node + 1, mid + 1, end, idx);
	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return segTree[node];

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
	cin >> n;

	A = vector<int>(n);
	segTree = vector<int>(4 * n);

	for (int& i : A)
	{
		cin >> i;
	}

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		B[num] = i;
	}

	ll ret = 0;
	for (int i = 0; i < n; i++)
	{
		int idx = B[A[i]];
		ret += query(1, 0, n - 1, idx + 1, n - 1);
		update(1, 0, n - 1, idx);
	}

	cout << ret << "\n";

	return 0;
}