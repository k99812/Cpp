#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = INT32_MAX;

int n;
vector<pair<int, int>> cordi;
vector<int> arr_x, arr_y, ret;

int main()
{
	cin >> n;
	cordi = vector<pair<int, int>>(n);
	ret = vector<int>(n + 1, INF);

	for (pair<int, int>& p : cordi)
	{
		cin >> p.first >> p.second;

		arr_x.push_back(p.first);
		arr_y.push_back(p.second);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int now_x = arr_x[i], now_y = arr_y[j];

			vector<int> dist;
			for (int k = 0; k < n; k++)
			{
				int d = abs(now_x - cordi[k].first) + abs(now_y - cordi[k].second);
				dist.push_back(d);
			}

			sort(dist.begin(), dist.end());

			int sum = 0;
			for (int k = 0; k < n; k++)
			{
				sum += dist[k];
				ret[k + 1] = min(ret[k + 1], sum);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << ret[i] << " ";
	}
	cout << "\n";

	return 0;
}