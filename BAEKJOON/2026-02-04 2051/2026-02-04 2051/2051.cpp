#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> match, visited;

int main()
{
	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	match.assign(m + 1, -1);

	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		for (int j = e; j < e; j++)
		{
			int to;
			cin >> to;
			graph[i].push_back(to);
		}
	}

	return 0;
}