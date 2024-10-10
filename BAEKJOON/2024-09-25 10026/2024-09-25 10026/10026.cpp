#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

#define MAX_NUM 100 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, visited[MAX_NUM][MAX_NUM];
char a[MAX_NUM][MAX_NUM];

void bfs(int y, int x, int flag)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;
	char target = a[y][x];

	while (q.size())
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i], nx = now.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (flag)
			{
				if (target == 'R' || target == 'G')
				{
					if (a[ny][nx] == 'B') continue;
				}
				else
				{
					if (a[ny][nx] != 'B') continue;
				}
			}
			else
			{
				if (a[ny][nx] != target) continue;
			}

			visited[ny][nx] = true;
			q.push({ ny, nx });
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	int c = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			bfs(i, j, 0);
			c++;
		}
	}

	fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], 0);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visited[i][j]) continue;
			bfs(i, j, 1);
			b++;
		}
	}

	cout << c << " " << b << "\n";

	return 0;
}