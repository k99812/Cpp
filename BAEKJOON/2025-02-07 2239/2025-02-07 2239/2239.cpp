#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

const int n = 9;

bool isPossible(int y, int x, int num, vector<vector<int>>& map)
{
	for (int i = 0; i < 9; i++)
	{
		if (map[y][i] == num && i != x) return false;

		if (map[i][x] == num && i != y) return false;

		int ny = y / 3 * 3 + i / 3;
		int nx = x / 3 * 3 + i % 3;

		if (map[ny][nx] == num && !(ny == y && nx == x)) return false;
	}

	return true;
}

void go(int idx, vector<vector<int>>& map, const vector<pair<int, int>>& empty)
{
	if (idx == empty.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}

		exit(0);
	}

	int y = empty[idx].first, x = empty[idx].second;

	for (int i = 1; i <= 9; i++)
	{
		if (isPossible(y, x, i, map))
		{
			map[y][x] = i;

			go(idx + 1, map, empty);

			map[y][x] = 0;
		}
	}

	return;
}

int main()
{
	vector<vector<int>> map(n);
	for (vector<int>& v : map) v.resize(n);

	vector<pair<int, int>> empty;

	for (int i = 0; i < 9; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < 9; j++)
		{
			map[i][j] = s[j] - '0';
			if (map[i][j] == 0) empty.push_back({ i, j });
		}
	}

	go(0, map, empty);

	return 0;
}