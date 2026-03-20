#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

typedef long long ll;

struct Edge
{
	double cost;
	int from, to;

	bool operator<(const Edge& other) const
	{
		return cost < other.cost;
	}
};

int n, m;
vector<int> parents;
vector<pair<ll, ll>> cordi;
vector<Edge> edge;

int getRoot(int num)
{
	if (parents[num] == num) return num;
	else return parents[num] = getRoot(parents[num]);
}

void unionParents(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);

	if (parent_a != parent_b)
	{
		if (parent_a > parent_b) swap(parent_a, parent_b);

		parents[parent_b] = parent_a;
	}
}

int main()
{
	cin >> n >> m;

	parents.assign(n + 1, 0);
	cordi.assign(n + 1, { 0, 0 });

	for (int i = 1; i <= n; i++) 
	{
		parents[i] = i;
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> cordi[i].first >> cordi[i].second;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		unionParents(a, b);
	}

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			ll dist_x = cordi[i].first - cordi[j].first;
			ll dist_y = cordi[i].second - cordi[j].second;

			double dist = sqrt((double)(dist_x * dist_x + dist_y * dist_y));
			edge.push_back({ dist, i, j });
		}
	}

	sort(edge.begin(), edge.end());

	double total_cost = 0;

	for (int i = 0; i < edge.size(); i++)
	{
		int from = edge[i].from, to = edge[i].to;

		if (getRoot(from) != getRoot(to))
		{
			unionParents(from, to);
			total_cost += edge[i].cost;
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << total_cost << "\n";

	return 0;
}