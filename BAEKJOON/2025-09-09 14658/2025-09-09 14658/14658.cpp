#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, l, k;
vector<pair<int, int>> stars;

int go(int y, int x)
{
	int cnt = 0;

	return cnt;
}

int main()
{
	cin >> m >> n >> l >> k;

	stars = vector<pair<int, int>>(k);

	for (int i = 0; i < k; i++)
	{
		cin >> stars[i].second >> stars[i].first;
	}

	int ret = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int y = stars[i].first, x = stars[j].second;

			int cnt = 0;
			for (int itr = 0; itr < k; itr++)
			{
				int ny = stars[itr].first, nx = stars[itr].second;
				if (y <= ny && ny <= y + l &&
					x <= nx && nx <= x + l)
				{
					cnt++;
				}
			}
			ret = max(ret, cnt);
		}
	}

	cout << k - ret << "\n";

	return 0;
}