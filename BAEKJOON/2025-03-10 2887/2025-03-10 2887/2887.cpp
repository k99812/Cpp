#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int getRoot(int num, vector<int>& parent)
{
	if (num == parent[num]) return num;
	return parent[num] = getRoot(parent[num], parent);
}

void unionParent(int a, int b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	if (parent_a != parent_b)
	{
		if (parent_a < parent_b)
		{
			parent[parent_b] = parent_a;
		}
		else
		{
			parent[parent_a] = parent_b;
		}
	}
}

bool find(int a, int b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	return parent_a == parent_b;
}

int main()
{
	cin >> n;

	vector<pair<int, pair<int, int>>> graph;
	vector<pair<int, int>> x, y, z;

	vector<int> parent(n);
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		int tx, ty, tz;
		cin >> tx >> ty >> tz;

		x.push_back({ tx, i });
		y.push_back({ ty, i });
		z.push_back({ tz, i });
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	sort(z.begin(), z.end());

	for (int i = 0; i < n - 1; i++)
	{
		graph.push_back({ x[i + 1].first - x[i].first, { x[i].second, x[i + 1].second} });
		graph.push_back({ y[i + 1].first - y[i].first, { y[i].second, y[i + 1].second} });
		graph.push_back({ z[i + 1].first - z[i].first, { z[i].second, z[i + 1].second} });
	}

	sort(graph.begin(), graph.end());

	int ret = 0;
	for (const pair<int, pair<int, int>>& now : graph)
	{
		if (!find(now.second.first, now.second.second, parent))
		{
			unionParent(now.second.first, now.second.second, parent);
			ret += now.first;
		}
	}

	cout << ret << "\n";

	return 0;
}