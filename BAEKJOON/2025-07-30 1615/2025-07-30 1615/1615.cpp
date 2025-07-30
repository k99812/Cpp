#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<pair<int, int>> v;
vector<int> segTree;

void update(int node, int start, int end, int idx, int num)
{
	if (idx < start || end < idx) return;

	if (start == end)
	{
		segTree[node] += num;
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, num);
	update(2 * node + 1, mid + 1, end, idx, num);
	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int query(int node, int start, int end, int left, int right)
{
	if (right < start || end < left) return 0;

	if (left <= start && end <= right)  
	{
		return segTree[node]; 
	}

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
	cin >> n >> m;

	v = vector<pair<int, int>>(m);
	segTree = vector<int>(4 * n);

	for (int i = 0; i < m; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end());

	long long ret = 0;
	for (const pair<int, int>& itr : v)
	{
		ret += query(1, 1, n, itr.second + 1, n);
		update(1, 1, n, itr.second, 1);
	}

	cout << ret << "\n";

	return 0;
}