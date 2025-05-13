#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int>> graph;

int main()
{
	cin >> n;
	graph = vector<vector<int>>(100, vector<int>(100));

	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		
		for (int i = y; i < y + 10; i++)
		{
			for (int j = x; j < x + 10; j++)
			{
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (graph[i][j])
			{
				ret++;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}