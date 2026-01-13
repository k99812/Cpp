#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Info
{
	long long size, speed, intell;
};

int n;
vector<vector<int>> graph;
vector<int> match;
vector<bool> visited;
vector<Info> sharks;

bool dfs(int now)
{
	for (const int next : graph[now])
	{
		if (visited[next]) continue;

		visited[next] = true;

		if (match[next] == -1 || dfs(match[next]))
		{
			match[next] = now;
			return true;
		}
	}
	
	return false;
}

int main()
{
	cin >> n;

	graph = vector<vector<int>>(n + 1);
	match = vector<int>(n + 1, -1);
	sharks = vector<Info>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> sharks[i].size >> sharks[i].speed >> sharks[i].intell;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;

			if (sharks[i].size >= sharks[j].size && sharks[i].speed >= sharks[j].speed
				&& sharks[i].intell >= sharks[j].intell)
			{
				if (sharks[i].size == sharks[j].size && sharks[i].speed == sharks[j].speed 
					&& sharks[i].intell == sharks[j].intell)
				{
					if (i > j) continue;
				}

				graph[i].push_back(j);
			}
		}
	}

	int match_num = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			visited.assign(n + 1, false);

			if (dfs(i))
			{
				match_num++;
			}
		}
	}

	cout << n - match_num << "\n";

	return 0;
}