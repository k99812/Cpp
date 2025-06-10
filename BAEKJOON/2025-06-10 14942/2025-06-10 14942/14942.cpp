#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> ant;
vector<vector<pair<int, int>>> graph;

int main()
{
	cin >> n;
	ant = vector<int>(n + 1);
	graph = vector<vector<pair<int, int>>>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> ant[i];
	}

	for (int i = 0; i < n - 1; i++)
	{
		int a, b, dist;
		cin >> a >> b >> dist;

		graph[a].push_back({ b, dist });
		graph[b].push_back({ a, dist });
	}

	return 0;
}