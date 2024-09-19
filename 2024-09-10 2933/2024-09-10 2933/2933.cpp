#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

#define MAX_NUM 100 + 4
#define INF 1e9

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int r, c, n, stick[MAX_NUM], visited[MAX_NUM][MAX_NUM];
vector<pair<int, int>> v;
char a[MAX_NUM][MAX_NUM];

void PrintMap()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << a[i][j];
		}
		cout << "\n";
	}
}

int cluster(int y, int x)
{
	int cnt = 0;

	for (int i = y + 1; i < r; i++)
	{
		if (a[i][x] == 'x')
		{
			if (visited[i][x] == 0) return INF;
			return cnt;
		}
		cnt++;
	}

	return cnt;
}

void gravity()
{
	int down = INF;
	for (int i = 0; i < v.size(); i++) 
	{
		int cnt = cluster(v[i].first, v[i].second);

		if (cnt == INF) continue;
		down = min(cnt, down);
	}

	if (down == INF) return;

	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first, x = v[i].second;
		a[y][x] = '.';
	}

	for (int i = 0; i < v.size(); i++)
	{
		int y = v[i].first, x = v[i].second;
		a[y + down][x] = 'x';
	}
}

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	visited[y][x] = true;
	q.push({ y, x });

	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
			if (a[ny][nx] == '.') continue;

			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
}

bool find_float()
{
	bool flag = false;
	for (int i = 0; i < c; i++)
	{
		if (visited[r - 1][i] || a[r - 1][i] == '.') continue;
		bfs(r - 1, i);
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (visited[i][j] || a[i][j] == '.') continue;
			v.push_back({ i, j });
			flag = true;
		}
	}

	return flag;
}

void go()
{
	for (int i = 0; i < n; i++)
	{
		fill(&visited[0][0], &visited[MAX_NUM - 1][MAX_NUM], 0);
		v.clear();

		int row = r - stick[i];

		if (i % 2)
		{
			for (int col = c - 1; col >= 0; col--)
			{
				if (a[row][col] == 'x')
				{
					a[row][col] = '.';
					break;
				}
			}
		}
		else
		{
			for (int col = 0; col < c; col++)
			{
				if (a[row][col] == 'x')
				{
					a[row][col] = '.';
					break;
				}
			}
		}

		if(!find_float()) continue;
		gravity();
	}
}

int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			a[i][j] = s[j];
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> stick[i];
	}

	go();

	PrintMap();

	return 0;
}