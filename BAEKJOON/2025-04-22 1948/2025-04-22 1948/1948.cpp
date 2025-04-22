#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, s, e;
vector<vector<pair<int, int>>> graph;

int main()
{
	cin >> n >> m;

	graph = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}

	cin >> s >> e;

	return 0;
}