#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAX_NUM 20000 + 4
#define RED 1
#define BLUE 2

using namespace std;

int t, visited[MAX_NUM];
vector<int> grap[MAX_NUM];

void bfs(const int& start)
{
	queue<int> q;
	visited[start] = RED;
	q.push(start);

	while (q.size())
	{
		int here = q.front();
		q.pop();

		for (int next : grap[here])
		{
			if (visited[next]) continue;
			q.push(next);
			visited[next] = visited[here] == RED ? BLUE : RED;
		}
	}
}

bool check(const int& v)
{
	for (int here = 1; here <= v; here++)
	{
		for (int next : grap[here])
		{
			if (visited[here] == visited[next]) return 0;
		}
	}
	return 1;
}

int main()
{
	cin >> t;

	while (t--)
	{
		fill(&visited[0], &visited[MAX_NUM], 0);
		for (int i = 0; i < MAX_NUM; i++) grap[i].clear();

		int v, e;

		cin >> v >> e;

		for (int i = 0; i < e; i++)
		{
			int from, to;
			cin >> from >> to;
			grap[from].push_back(to);
			grap[to].push_back(from);
		}

		for (int i = 1; i <= v; i++)
		{
			if (visited[i]) continue;
			bfs(i);
		}

		cout << (check(v) ? "YES\n" : "NO\n");
	}

	return 0;
}