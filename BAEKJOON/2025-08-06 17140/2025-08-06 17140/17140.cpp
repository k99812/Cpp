#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int r, c, k;
int n = 3, m = 3;
vector<vector<int>> arr;

int go()
{
	int time = 0;

	while (time <= 100)
	{
		if (r < n && c < m && arr[r][c] == k) return time;

		if(n >= m)
		{
			int max_m = 0;
			vector<vector<int>> temp(n);

			for (int i = 0; i < n; i++)
			{
				map<int, int> cnt_map;

				for (int j = 0; j < m; j++)
				{
					if (arr[i][j] == 0) continue;

					cnt_map[arr[i][j]]++;
				}

				vector<pair<int, int>> v;

				for (const auto& itr : cnt_map)
				{
					v.push_back({ itr.second, itr.first });
				}

				sort(v.begin(), v.end());

				for (const pair<int, int>& p : v)
				{
					temp[i].push_back(p.second);
					temp[i].push_back(p.first);
				}

				if (temp[i].size() > 100) temp[i].resize(100);
				max_m = max(max_m, (int)temp[i].size());
			}

			for (int i = 0; i < n; i++) 
			{
				if (temp[i].size() < max_m) temp[i].resize(max_m, 0);
			}

			m = max_m;
			arr = move(temp);
		}
		else
		{
			int max_n = 0;
			vector<vector<int>> temp;

			temp.resize(100, vector<int>(m));

			for (int j = 0; j < m; j++)
			{
				map<int, int> cnt_map;

				for (int i = 0; i < n; i++)
				{
					if (arr[i][j] == 0) continue;
					cnt_map[arr[i][j]]++;
				}

				vector<pair<int, int>> v;

				for (const auto& itr : cnt_map)
				{
					v.push_back({ itr.second, itr.first });
				}

				sort(v.begin(), v.end());

				int idx = 0;
				for (const pair<int, int>& p : v)
				{
					if (idx >= 100) break;
					temp[idx++][j] = p.second;
					if (idx >= 100) break;
					temp[idx++][j] = p.first;
				}

				max_n = max(max_n, idx);
			}

			temp.resize(max_n);
			arr = temp;
			n = max_n;
		}

		time++;
	}

	return -1;
}

int main()
{
	cin >> r >> c >> k;
	r--, c--;

	arr = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << go() << "\n";


	return 0;
}