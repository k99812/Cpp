#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int n;
char a[10][10];
vector<pair<int, int>> teacher, em;

bool check(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i], nx = x + dx[i];

		while (!(ny < 0 || nx < 0 || ny >= n || nx >= n))
		{
			if (a[ny][nx] == 'S') return false;
			if (a[ny][nx] == 'O') break;

			ny += dy[i], nx += dx[i];
		}
	}

	return true;
}

void dfs(int idx, int cnt)
{
	if (cnt == 3)
	{
		for (pair<int, int> p : teacher)
		{
			if (!check(p.first, p.second))
			{
				return;
			}
		}

		cout << "YES" << "\n";
		exit(0);
	}

	for (int i = idx; i < em.size(); i++)
	{
		a[em[i].first][em[i].second] = 'O';
		dfs(i + 1, cnt + 1);
		a[em[i].first][em[i].second] = 'X';
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'T') teacher.push_back({ i,j });
			else if (a[i][j] == 'X') em.push_back({ i,j });
		}
	}

	dfs(0, 0);

	cout << "NO" << "\n";

	return 0;
}