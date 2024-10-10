#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

const int MAX = 1501;
int r, c, visited[MAX + 4][MAX + 4], SwanVisited[MAX + 4][MAX + 4], cnt, ty, tx;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char  map[MAX + 4][MAX + 4];
queue<pair<int, int>> water, waterTemp, qSwan, qSwanTemp;
pair<int, int> swan;
string s;

void qClear(queue<pair<int, int>>& q)
{
	queue<pair<int, int>> empty;
	swap(q, empty);
}

void printM()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void ice_melting()
{
	while (water.size())
	{
		tie(ty, tx) = water.front(); water.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i], nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == 'X')
			{
				waterTemp.push({ ny, nx });
				visited[ny][nx] = 1;
				map[ny][nx] = '.';
			}
		}
	}
	cout << "\n";
	printM();
}

bool MoveSwan()
{
	while (qSwan.size())
	{
		tie(ty, tx) = qSwan.front(); qSwan.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = ty + dy[i], nx = tx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (SwanVisited[ny][nx]) continue;
			SwanVisited[ny][nx] = 1;
			if(map[ny][nx] == '.') qSwan.push({ ny, nx });
			else if (map[ny][nx] == 'X') qSwanTemp.push({ ny, nx });
			else if (map[ny][nx] == 'L') return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
			if (map[i][j] == 'L') swan = { i, j };
			if (map[i][j] == '.' || map[i][j] == 'L')
			{
				water.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	qSwan.push({ swan.first, swan.second });
	SwanVisited[swan.first][swan.second] = 1;

	while (true)
	{
		if (MoveSwan()) break;
		ice_melting();
		water = waterTemp;
		qSwan = qSwanTemp;
		qClear(waterTemp);
		qClear(qSwanTemp);
		cnt++;
	}

	cout << "\n";
	cout << cnt << "\n";
	return 0;
}