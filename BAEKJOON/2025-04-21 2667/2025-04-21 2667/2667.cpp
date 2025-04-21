#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int n;
vector<vector<int>> map, visited;

int bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	int cnt = 1;
	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] || !map[ny][nx]) continue;

			q.push({ ny, nx });
			visited[ny][nx] = true;
			++cnt;
		}
	}

	return cnt;
}

int main()
{
	cin >> n;
	map = visited = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j] || !map[i][j]) continue;
			pq.push(bfs(i, j));
		}
	}

	cout << pq.size() << "\n";
	while (pq.size())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}