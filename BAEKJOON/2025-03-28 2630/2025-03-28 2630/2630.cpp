#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, white, blue;
vector<vector<int>> map;

bool isOneColor(int y, int x, int size)
{
	int color = map[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (color != map[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void go(int y, int x, int size)
{
	if (isOneColor(y, x, size))
	{
		map[y][x] == 0 ? white++ : blue++;
		return;
	}

	int nextSize = size / 2;

	go(y, x, nextSize);
	go(y, x + nextSize, nextSize);
	go(y + nextSize, x, nextSize);
	go(y + nextSize, x + nextSize, nextSize);
}

int main()
{
	cin >> n;

	map.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	go(0, 0, n);

	cout << white << "\n" << blue << "\n";

	return 0;
}