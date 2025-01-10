#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getRoot(int a, vector<int>& parent)
{
	if (a == parent[a]) return a;
	return parent[a] = getRoot(parent[a], parent);
}

void unionParent(int a, int b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);

	if (parent_a != parent_b)
	{
		parent[parent_a] = parent_b;
	}
}

bool find(int a, int b, vector<int>& parent)
{
	int parent_a = getRoot(a, parent), parent_b = getRoot(b, parent);
	return parent_a == parent_b;
}

int main()
{
	int v, e;
	cin >> v >> e;

	vector<pair<int, pair<int, int>>> graph;
	vector<int> parent(v + 1);

	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph.push_back({ cost, {from, to} });
	}

	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}

	sort(graph.begin(), graph.end());

	int ret = 0;
	for (const pair<int, pair<int, int>>& now:graph)
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