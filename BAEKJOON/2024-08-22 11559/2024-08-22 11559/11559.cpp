#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
string s;
char a[12][6];
int visited[12][6];

bool bfs(int y, int x, char color)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	fill(&visited[0][0], &visited[11][6], 0);
	q.push({ y, x });
	v.push_back({ y, x });
	visited[y][x] = 1;

	while (q.size())
	{
		int cy = q.front().first, cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= 12 || nx >= 6 || visited[ny][nx]) continue;
			if (a[ny][nx] == '.' || a[ny][nx] != color) continue;

			q.push({ ny, nx });
			v.push_back({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	if (v.size() >= 4)
	{
		for (const pair<int, int>& p : v)
		{
			a[p.first][p.second] = '.';
		}

		return true;
	}

	return false;
}

void down() 
{
	for (int i = 0; i < 6; i++) 
	{ 
		queue<char> q;
		for (int j = 11; j >= 0; j--) 
		{
			if (a[j][i] != '.') 
			{
				q.push(a[j][i]);
			}
		}

		int qs = q.size();
		for (int j = 11; j >= 12 - qs; j--) 
		{
			a[j][i] = q.front(); 
			q.pop();
		}

		for (int j = 11 - qs; j >= 0; j--) 
		{
			a[j][i] = '.';
		}
	}
}

int main()
{
	for (int i = 0; i < 12; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			a[i][j] = s[j];
		}
	}

	int cnt = 0;
	while (true)
	{
		int flag = false;

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < s.size(); j++)
			{
				if (a[i][j] == '.') continue;
				if (bfs(i, j, a[i][j]))
				{
					flag = true;
				}
				
			}
		}

		if (!flag) break;
		cnt++;
		down();
	}

	cout << cnt << "\n";

	return 0;
}