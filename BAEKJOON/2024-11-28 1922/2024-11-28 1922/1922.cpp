#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, ret;

int getRoot(int num, vector<int>& parent)
{
	if (parent[num] == num) return num;
	return parent[num] = getRoot(parent[num], parent);
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
	if (parent_a == parent_b) return true;
	else return false;
}


int main()
{
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> graph;
	vector<int> parents(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		graph.push_back({ cost, {from, to} });
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= n; i++) 
	{
		parents[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int cost = graph[i].first;
		int a = graph[i].second.first;
		int b = graph[i].second.second;

		if (!find(a, b, parents))
		{
			ret += cost;
			unionParent(a, b, parents);
		}
	}

	cout << ret << "\n";

	return 0;
}