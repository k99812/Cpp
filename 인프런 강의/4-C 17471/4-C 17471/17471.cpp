#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>

using namespace std;

const int MAX = 14, INF = 1e8;
int n, m, pop[MAX], visited[MAX], comp[MAX], ret = INF, temp;
vector<int> adj[MAX];

pair<int, int> dfs(int here, int val)
{
	visited[here] = 1;
	pair<int, int> re = { 1, pop[here] };
	for (int there : adj[here])
	{
		if (comp[there] != val) continue;
		if (visited[there]) continue;
		pair<int, int> temp = dfs(there, val);
		re.first += temp.first;
		re.second += temp.second;
	}
	return re;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> pop[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			adj[i].push_back(temp);
			adj[temp].push_back(i);
		}
	}

	for (int i = 1; i < (1 << n) - 1; i++)
	{
		fill(&visited[0], &visited[MAX - 1], 0);
		fill(&comp[0], &comp[MAX - 1], 0);
		int idx1 = -1, idx2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				comp[j + 1] = 1;
				idx1 = j + 1;
			}
			else idx2 = j + 1;
		}
		pair<int, int> comp1 = dfs(idx1, 1);
		pair<int, int> comp2 = dfs(idx2, 0);
		if (comp1.first + comp2.first == n) ret = min(ret, abs(comp1.second - comp2.second));
	}
	cout << (ret == INF ? -1 : ret) << "\n";
	return 0;
}