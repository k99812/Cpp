#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, ret;

int getRoot(int num, vector<int>& parents)
{
	if (num == parents[num]) return num;
	return parents[num] = getRoot(parents[num], parents);
}

void unionParent(int a, int b, vector<int>& parents)
{
	int parent_a = getRoot(a, parents), parent_b = getRoot(b, parents);
	if (parent_a != parent_b)
	{
		parents[parent_a] = parent_b;
	}
}

bool find(int a, int b, vector<int>& parents)
{
	int parent_a = getRoot(a, parents), parent_b = getRoot(b, parents);
	if (parent_a == parent_b) return true;
	return false;
}

int main()
{
	cin >> n >> m;
	vector<pair<int, pair<int, int>>> grap;
	vector<int> parents(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		grap.push_back({ cost, {from, to} });
	}

	sort(grap.begin(), grap.end());

	for (int i = 1; i <= n; i++)
	{
		parents[i] = i;
	}

	int max_cost = 0;
	for (int i = 0; i < m; i++)
	{
		int cost = grap[i].first, here = grap[i].second.first, next = grap[i].second.second;

		if (!find(here, next, parents))
		{
			max_cost = max(max_cost, cost);
			ret += cost;
			unionParent(here, next, parents);
		}
	}

	cout << ret - max_cost << "\n";

	return 0;
}