#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, l, m;
vector<pair<int, int>> fish;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> l >> m;
	fish = vector<pair<int, int>>(m);

	for (int i = 0; i < m; i++)
	{
		cin >> fish[i].first >> fish[i].second;
	}

	int ret = 0;
	for (int h = 1; h < l / 2; h++)
	{
		int w = l / 2 - h;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int y = min(fish[i].first, n - h), x = min(fish[j].second, n - w);

				int cnt = 0;
				for (int k = 0; k < fish.size(); k++)
				{
					if (y <= fish[k].first && fish[k].first <= y + h
						&& x <= fish[k].second && fish[k].second <= x + w) cnt++;
				}

				ret = max(ret, cnt);
			}
		}
	}

	cout << ret << "\n";

	return 0;
}