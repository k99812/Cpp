#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr, segTree, comp;

void update(int node, int start, int end, int idx)
{
	if (idx < start || end < idx) return;

	segTree[node]++;

	if (start == end) return;

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx);
	update(2 * node + 1, mid + 1, end, idx);
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

	arr = vector<int>(n);
	segTree = vector<int>(4 * n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	comp = arr;
	sort(comp.begin(), comp.end());

	for (int i = 0; i < n; i++)
	{
		int rank = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin();
		int cnt = (rank == 0 ? 0 : query(1, 0, n - 1, 0, rank - 1));
		int best = (i + 1) - cnt;
		cout << best << "\n";
		update(1, 0, n - 1, rank);
	}

	return 0;
}