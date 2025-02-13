#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;

int getRoot(int num, vector<int>& parent)
{
	if (num == parent[num]) return num;
	return parent[num] = getRoot(parent[num], parent);
}

void unionParent(int& a, int& b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	if (parent_a != parent_b)
	{
		parent[parent_b] = parent_a;
	}
}

bool findParent(int& a, int& b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	return parent_a == parent_b;
}

int main()
{
	cin >> n >> m;

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<pair<int, int>> edge;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		edge.push_back({ from, to });
		edge.push_back({ to, from });
	}

	sort(edge.begin(), edge.end());

	for (pair<int, int> now : edge)
	{
		unionParent(now.first, now.second, parent);
	}

	int ret = 0;
	vector<int> check(n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (!check[parent[i]])
		{
			ret++;
			check[parent[i]]++;
		}
	}

	cout << ret << "\n";

	return 0;
}