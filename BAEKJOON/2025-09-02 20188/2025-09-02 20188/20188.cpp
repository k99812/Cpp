#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int>> graph;

int main()
{
	cin >> n;

	graph = vector<vector<int>>(n + 1);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	return 0;
}