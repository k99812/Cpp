#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

struct Edge
{
	int u, v;
	double cost;

	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

int n;
vector<int> parents;
vector<pair<double, double>> cordi;

int getRoot(int num)
{
	if (parents[num] == num) return num;
	return parents[num] = getRoot(parents[num]);
}

void unionParent(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	if (parent_a != parent_b)
	{
		if (parent_b > parent_a) swap(parent_a, parent_b);

		parents[parent_b] = parent_a;
	}
}

int main()
{
	cin >> n;

	parents.assign(n + 1, 0);
	cordi.assign(n + 1, { 0.0, 0.0 });

	for (int i = 1; i <= n; i++)
	{
		parents[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> cordi[i].first >> cordi[i].second;
	}

	vector<Edge> edge;
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			double dist_x = cordi[i].first - cordi[j].first;
			double dist_y = cordi[i].second - cordi[j].second;
			double dist = sqrt(dist_x * dist_x + dist_y * dist_y);

			edge.push_back({ i, j, dist });
		}
	}

	sort(edge.begin(), edge.end());

	double ret = 0.0f;
	for (int i = 0; i < edge.size(); i++)
	{
		int u = edge[i].u, v = edge[i].v;

		if (getRoot(u) == getRoot(v)) continue;

		ret += edge[i].cost;
		unionParent(u, v);
	}

	cout << fixed;
	cout.precision(2);
	cout << ret << "\n";

	return 0;
}