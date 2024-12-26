#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T;

void dfs(int here, int& ret, vector<int>& visited, vector<int>& v, vector<int>& group)
{
	visited[here] = true;

	int next = v[here];

	if (!visited[next])
	{
		dfs(next, ret, visited, v, group);
	}
	else if(!group[next])
	{
		for (int i = next; i != here; i = v[i])
		{
			ret++;
		}
		ret++;
	}

	group[here] = true;
}

int main()
{
	cin >> T;
	
	while (T--)
	{
		int n, ret = 0;
		cin >> n;
		vector<int> v(n + 1);
		vector<int> visited(n + 1);
		vector<int> group(n + 1);

		for (int i = 1; i <= n; i++)
		{
			cin >> v[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (visited[i]) continue;
			dfs(i, ret, visited, v, group);
		}

		cout << n - ret << "\n";
	}

	return 0;
}