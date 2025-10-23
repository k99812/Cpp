#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> arr, ans, visited;

void dfs(int now, int start)
{
	visited[now] = true;

	int next = arr[now];
	if (next == start)
	{
		ans[start] = true;
		return;
	}

	if (visited[next]) return;
	dfs(next, start);
}

int main()
{
	cin >> n;

	arr = ans = vector<int>(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		visited = vector<int>(n + 1);

		dfs(i, i);
	}

	int cnt = 0;
	vector<int> ret;
	for (int i = 1; i <= n; i++)
	{
		if (ans[i])
		{
			cnt++;
			ret.push_back(i);
		}
		
	}

	cout << cnt << "\n";
	for (const int& i : ret)
	{
		cout << i << "\n";
	}

	return 0;
}