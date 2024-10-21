#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 100000 + 4

using namespace std;

const int dx[] = { -1, 1, 2 };
int n, k, visited[MAX_NUM];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (q.size())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			int next;

			if (dx[i] == 2) next = now * dx[i];
			else next = now + dx[i];

			if (next < 0 || next > MAX_NUM - 4) continue;
			if (visited[next]) continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}

int main()
{
	cin >> n >> k;

	bfs(n);

	cout << visited[k] - 1 << "\n";

	return 0;
}