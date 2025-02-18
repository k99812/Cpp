#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getRoot(int num, vector<int>& parents)
{
	if (num == parents[num]) return num;
	return parents[num] = getRoot(parents[num], parents);
}

void unionParent(int a, int b, vector<int>& parents)
{
	int parent_a = getRoot(a, parents), parent_b = getRoot(b, parents);

	if (parent_a < parent_b)
	{
		parents[parent_b] = parent_a;
	}
	else
	{
		parents[parent_a] = parent_b;
	}
}

bool findParent(int a, int b, vector<int>& parents)
{
	int parent_a = getRoot(a, parents), parent_b = getRoot(b, parents);
	return parent_a == parent_b;
}

int main()
{
	while (true)
	{
		int n, m, total = 0;
		cin >> n >> m;

		if (!n && !m) break;

		vector<int> parents(n);
		for (int i = 0; i < n; i++)
		{
			parents[i] = i;
		}

		vector<pair<int, pair<int, int>>> graph;

		for (int i = 0; i < m; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;

			graph.push_back({ z, { x, y } });
			total += z;
		}

		sort(graph.begin(), graph.end());

		int sum = 0;
		for (const pair<int, pair<int, int>>& now : graph)
		{
			int cost = now.first, x = now.second.first, y = now.second.second;

			if (!findParent(x, y, parents))
			{
				unionParent(x, y, parents);
				sum += cost;
			}
		}

		cout << total - sum << "\n";
	}

	return 0;
}