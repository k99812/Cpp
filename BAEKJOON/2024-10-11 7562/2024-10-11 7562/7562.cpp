#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 300 + 4 

using namespace std;

const int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int t, n, a[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];

int bfs(const pair<int, int>& start, const pair<int, int>& des)
{
	queue<pair<int, int>> q;
	visited[start.first][start.second] = 1;
	q.push(start);

	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx]) continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}

	return visited[des.first][des.second] - 1;
}

int main()
{
	cin >> t;

	while (t--)
	{
		fill(&a[0][0], &a[MAX_NUM - 1][MAX_NUM], 0);
		fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], 0);
		pair<int, int> start, des;

		cin >> n;

		cin >> start.first >> start.second >> des.first >> des.second;

		cout << bfs(start, des) << "\n";
	}

	return 0;
}