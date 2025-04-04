#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<vector<int>> map;
vector<int> ret(3);

bool isOne(int y, int x, int size)
{
	int num = map[y][x];

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (num != map[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void go(int y, int x, int size)
{
	if (isOne(y, x, size))
	{
		if (map[y][x] == -1)
		{
			ret[0]++;
		}
		else if (map[y][x] == 0)
		{
			ret[1]++;
		}
		else
		{
			ret[2]++;
		}

		return;
	}

	int next_size = size / 3;
	go(y, x, next_size);
	go(y, x + next_size, next_size);
	go(y, x + next_size * 2, next_size);

	go(y + next_size, x, next_size);
	go(y + next_size, x + next_size, next_size);
	go(y + next_size, x + next_size * 2, next_size);

	go(y + next_size * 2, x, next_size);
	go(y + next_size * 2, x + next_size, next_size);
	go(y + next_size * 2, x + next_size * 2, next_size);
}

int main()
{
	cin >> n;

	map = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	go(0, 0, n);

	for (const int& i : ret)
	{
		cout << i << "\n";
	}

	return 0;
}