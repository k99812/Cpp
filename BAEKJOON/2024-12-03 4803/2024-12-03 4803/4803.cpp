#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;

bool dfs(int start, int prev, const vector<vector<int>>& grap, vector<int>& visited)
{
	visited[start] = true;

	bool ret = true;

	for (int next : grap[start])
	{
		if (next == prev) continue;
		if (visited[next]) return false;

		ret = dfs(next, start, grap, visited);
		if (!ret) return false;
	}

	return ret;
}

int main()
{
	int T = 1;
	while (cin >> n >> m)
	{
		if (!n && !m)
		{
			break;
		}

		vector<vector<int>> grap(n + 1);
		vector<int> visited(n + 1);

		for (int i = 0; i < m; i++)
		{
			int from, to;
			cin >> from >> to;

			grap[from].push_back(to);
			grap[to].push_back(from);
		}

		int cnt = 0;

		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;

			if (dfs(i, 0, grap, visited))
			{
				++cnt;
			}
		}

		cout << "Case " << T << ": ";

		if (cnt)
		{
			if (cnt == 1)
			{
				cout << "There is one tree.\n";
			}
			else
			{
				cout << "A forest of " << cnt << " trees.\n";
			}
		}
		else
		{
			cout << "No trees.\n";
		}

		++T;
	}

	return 0;
}