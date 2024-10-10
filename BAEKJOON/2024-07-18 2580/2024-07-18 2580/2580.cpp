#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int a[10][10];
bool isPrint;
vector<pair<int, int>> cordi;

bool Check(pair<int, int> p, int value)
{
	for (int i = 0; i < 9; i++)
	{
		if (value == a[i][p.second] || value == a[p.first][i])
		{
			return true;
		}
	}

	int y_start = (p.first / 3) * 3, x_start = (p.second / 3) * 3;

	for (int i = y_start; i <= y_start + 2; i++)
	{
		for (int j = x_start; j <= x_start + 2; j++)
		{
			if (value == a[i][j])
			{
				return true;
			}
		}
	}

	return false;
}

void go(int idx)
{
	if (isPrint) return;
	if (idx == cordi.size())
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}

		isPrint = true;

		return;
	}

	for (int i = 1; i <= 9; i++)
	{
		if (Check(cordi[idx], i)) continue;

		a[cordi[idx].first][cordi[idx].second] = i;
		go(idx + 1);
		a[cordi[idx].first][cordi[idx].second] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
			if (!a[i][j])
			{
				cordi.push_back({ i, j });
			}
		}
	}

	go(0);

	return 0;
}