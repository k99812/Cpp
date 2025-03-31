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
vector<int> parent;

int getRoot(int num)
{
	if (num == parent[num]) return num;
	return parent[num] = getRoot(parent[num]);
}

void unionParent(int a, int b)
{
	int parent_a = getRoot(a), parent_b = getRoot(b);
	if (parent_a != parent_b)
	{
		if (parent_b < parent_a)
		{
			parent[parent_a] = parent_b;
		}
		else
		{
			parent[parent_b] = parent_a;
		}
	}
}

int main()
{
	cin >> n >> m;

	map.resize(n, vector<char>(m));
	parent.resize(n * m);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j];
			parent[i * m + j] = i * m + j;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int d;
			for (int k = 0; k < 4; k++)
			{
				if (map[i][j] == dir[k])
				{
					d = k;
					break;
				}
			}

			int ny = i + dy[d], nx = j + dx[d];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			unionParent(i * m + j, ny * m + nx);
		}
	}

	for (int i = 0; i < n * m; i++)
	{
		if (getRoot(i) == i)
		{
			ret++;
		}
	}

	cout << ret << "\n";

	return 0;
}