#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
const char dir[] = { 'U', 'R', 'D', 'L' };

int n, m, ret;
vector<vector<char>> map;
vector<vector<int>> visited;

void dfs(int y, int x)
{
	visited[y][x] = 1;

	int d;
	for (int i = 0; i < 4; i++)
	{
		if (map[y][x] == dir[i])
		{
			d = i;
			break;
		}
	}

	int ny = y + dy[d], nx = x + dx[d];

	if (ny < 0 || nx < 0 || ny >= n || nx >= m) return;
	if (!visited[ny][nx])
	{
		dfs(ny, nx);
	}
	else if(visited[ny][nx] == 1)
	{ 
		ret++;
	}
	
	visited[y][x] = 2;
}

int main()
{
	cin >> n >> m;

	map.resize(n, vector<char>(m));
	visited.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (visited[i][j]) continue;

			dfs(i, j);
		}
	}

	cout << ret << "\n";

	return 0;
}