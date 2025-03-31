#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, white, blue;
vector<vector<int>> map;

bool isColor(int y, int x, int size)
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
	if (isColor(y, x, size))
	{
		map[y][x] ? blue++ : white++;
		return;
	}

	int next_size = size / 2;
	
	go(y, x, next_size);
	go(y, x + next_size, next_size);
	go(y + next_size, x, next_size);
	go(y + next_size, x + next_size, next_size);
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