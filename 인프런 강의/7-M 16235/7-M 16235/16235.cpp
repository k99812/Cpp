#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int n, m, k, a[11][11], map[11][11], y, x, z;
vector<int> trees[11][11];

void spring()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (trees[i][j].size() == 0) continue;

			sort(trees[i][j].begin(), trees[i][j].end());
			vector<int> temp;
			int die = 0;
			
			for (int a : trees[i][j])
			{
				if (map[i][j] >= a) 
				{ 
					temp.push_back(a + 1); 
					map[i][j] -= a;
				}
				else die += a / 2;
			}
			trees[i][j] = temp;
			map[i][j] += die;
		}
	}
}

void autumn()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (trees[i][j].size() == 0) continue;
			for (int tree : trees[i][j])
			{
				if (tree % 5 == 0)
				{
					for (int k = 0; k < 8; k++)
					{
						int ny = i + dy[k], nx = j + dx[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
						trees[ny][nx].push_back(1);
					}
				}
			}
		}
	}
}

void winter()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			map[i][j] += a[i][j];
		}
	}
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	fill(&map[0][0], &map[10][11], 5);
	
	for (int i = 0; i < m; i++) 
	{
		cin >> y >> x >> z;
		y--, x--;
		trees[y][x].push_back(z);
	}

	while (k--)
	{
		spring();
		autumn();
		winter();
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cnt += trees[i][j].size();
		}
	}

	cout << cnt << "\n";

	return 0;
}