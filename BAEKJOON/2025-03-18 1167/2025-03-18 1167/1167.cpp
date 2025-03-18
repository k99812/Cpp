#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;

int main()
{
	cin >> n;

	vector<pair<int, int>> graph(n + 1);

	for (int from = 1; from <= n; from++)
	{
		int to, dist;

		while (cin >> to)
		{
			if (to == -1) break;

			cin >> dist;

			graph[from] = { dist, to };
			graph[to] = { dist, from };
		}
	}

	return 0;
}