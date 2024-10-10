#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

#define n 5
#define MAX_NUM 25
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int visited[n + 3][n + 3], ret;
char a[n + 3][n + 3];
string s;
vector<int> selected;

bool moreFour(const vector<int>& v)
{
	int cnt = 0;
	for (int i : v)
	{
		int y = i / 5, x = i % 5;

		if (a[y][x] == 'S') cnt++;
	}

	if (cnt >= 4)
	{
		return true;
	}
	
	return false;
}

bool bfs(const vector<int>& v)
{
	bool mems[n + 3][n + 3];
	queue<pair<int, int>> q;
	fill(&mems[0][0], &mems[n + 2][n + 3], false);
	fill(&visited[0][0], &visited[n+2][n+3], 0);

	for (int i : v)
	{
		int y = i / 5, x = i % 5;

		mems[y][x] = 1;
	}


	q.push({ v[0] / 5, v[0] % 5 });
	visited[v[0] / 5][v[0] % 5] = true;
	int cnt = 1;
	while (q.size())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		if (cnt == 7)
		{
			return true;
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i], nx = x + dx[i];

			if (ny<0 || nx<0 || ny > n || nx > n) continue;
			if (visited[ny][nx]) continue;
			if (!mems[ny][nx]) continue;

			visited[ny][nx] = true;
			q.push({ ny, nx });
			cnt++;
		}
	}

	return false;
}

void combi(int idx, vector<int>& selected)
{
	if (selected.size() == 7)
	{
		if (moreFour(selected))
		{
			if (bfs(selected))
			{
				ret++;
			}
		}

		return;
	}

	for (int i = idx + 1; i < MAX_NUM; i++)
	{
		selected.push_back(i);
		combi(i, selected);
		selected.pop_back();
	}

	return;
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	combi(-1, selected);

	cout << ret << "\n";

	return 0;
}