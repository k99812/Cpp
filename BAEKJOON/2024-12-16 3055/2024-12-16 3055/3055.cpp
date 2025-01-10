#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n, m;

void bfs(const pair<int,int>& start, const vector<pair<int, int>>& water, const vector<vector<char>>& map, vector<vector<int>>& vistied)
{
	queue<pair<char, pair<int, int>>> q;
	for (pair<int, int> w : water)
	{
		q.push({ '*', {w.first, w.second} });
		vistied[w.first][w.second] = -1;
	}
	q.push({ 'S', {start.first, start.second} });
	vistied[start.first][start.second] = 1;

	while (q.size())
	{
		char now = q.front().first;
		int cy = q.front().second.first, cx = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || map[ny][nx] == 'X') continue;
			if (now == '*')
			{
				if (map[ny][nx] == 'D') continue;
				if (vistied[ny][nx] == -1 || vistied[ny][nx]) continue;
				vistied[ny][nx] = vistied[cy][cx] - 1;
				q.push({ '*', {ny, nx} });
			}
			else if (now == 'S')
			{
				if (vistied[ny][nx] < 0 || vistied[ny][nx]) continue;
				vistied[ny][nx] = vistied[cy][cx] + 1;
				q.push({ 'S', {ny, nx} });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	vector<vector<char>> map(n);
	for (vector<char>& v : map) v.resize(m);

	vector<vector<int>> vistied(n);
	for (vector<int>& v : vistied) v.resize(m);

	pair<int, int> start, des;
	vector<pair<int, int>> water;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j];

			if (map[i][j] == 'D') des = { i, j };
			else if (map[i][j] == 'S') start = { i, j };
			else if (map[i][j] == '*') water.push_back({ i, j });
		}
	}

	bfs(start, water, map, vistied);

	if (vistied[des.first][des.second])
	{
		cout << vistied[des.first][des.second] - 1 << "\n";
	}
	else
	{
		cout << "KAKTUS" << "\n";
	}

	return 0;
}