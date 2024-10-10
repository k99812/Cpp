#include<iostream>
#include<algorithm>
#include<queue>

#define MAX_NUM 300 + 4

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m, a[MAX_NUM][MAX_NUM], original[MAX_NUM][MAX_NUM], visited[MAX_NUM][MAX_NUM];
queue<pair<int, int>> cordi;

void melt()
{
	while (cordi.size())
	{
		int y = cordi.front().first, x = cordi.front().second;
		cordi.pop();

		a[y][x] = max(0, a[y][x] - 1);
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;
			if (!original[ny][nx])
			{
				cordi.push({ cy, cx });
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	melt();
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int year = 0;
	while (true)
	{
		int land = 0;
		fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], 0);
		copy(&a[0][0], &a[MAX_NUM - 1][MAX_NUM], &original[0][0]);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!a[i][j]) continue;
				if (visited[i][j]) continue;
				bfs(i, j);
				land++;
			}
		}

		if (land >= 2)
		{
			cout << year << "\n";
			break;
		}
		if (!land)
		{
			cout << 0 << "\n";
			break;
		}

		year++;
	}

	return 0;
}