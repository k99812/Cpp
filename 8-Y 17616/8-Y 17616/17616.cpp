#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n, m, x, a, b, visited[100004];
vector<int> front[100004], back[100004];
queue<int> q;

int bfs(const vector<int>* grap ,int start)
{
	fill(&visited[0], &visited[100004], 0);

	visited[start] = 1;
	q.push(start);
	int ret = 0;

	while (q.size())
	{
		int s = q.front(); q.pop();

		for (int nx : grap[s])
		{
			if (visited[nx] != 0) continue;

			visited[nx] = 1;
			q.push(nx);
			ret++;
		}
	}

	return ret;
}

int main()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		back[a].push_back(b);
		front[b].push_back(a);
	}

	int f = bfs(front, x);
	int ba = bfs(back, x);

	cout << 1 + f << " " << n - ba << "\n";

	return 0;
}