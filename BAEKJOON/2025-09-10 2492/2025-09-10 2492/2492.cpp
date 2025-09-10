#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, t, k;
vector<pair<int, int>> diamond;

int main()
{
	cin >> n >> m >> t >> k;

	diamond = vector<pair<int, int>>(t);

	for (int i = 0; i < t; i++)
	{
		cin >> diamond[i].first >> diamond[i].second;
	}

	int ret = 0, best_y = 0, best_x = 0;

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < t; j++)
		{
			int x = min(diamond[i].first, n - k), y = min(diamond[j].second, m - k);

			int cnt = 0;
			for (int itr = 0; itr < t; itr++)
			{
				int nx = diamond[itr].first, ny = diamond[itr].second;

				if (y <= ny && ny <= y + k &&
					x <= nx && nx <= x + k) cnt++;
			}
			
			if (cnt > ret)
			{
				ret = cnt;
				best_y = y + k, best_x = x;
			}
		}
	}

	cout << best_x << " " << best_y << "\n" << ret << "\n";

	return 0;
}