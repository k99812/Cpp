#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, t, x, d, k, ret;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
vector <vector<int>> v(54);
vector <vector<int>> temp_v;

void erase()
{
	int sum = 0, cnt = 0;
	bool isChange = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += v[i][j];
			if (v[i][j] == 0) continue;
			cnt++;
			for (int k = 0; k < 4; k++)
			{
				int ny = i + dy[k], nx = j + dx[k];

				if (ny < 0) continue;
				else if(nx < 0) nx += m;
				if (ny >= n) continue;
				else if (nx >= m) nx %= m;

				if (temp_v[ny][nx] == 0) continue;
				if (v[i][j] == v[ny][nx])
				{
					temp_v[i][j] = 0;
					temp_v[ny][nx] = 0;
					isChange = true;
				}
			}
		}
	}

	if (isChange)
	{
		copy(temp_v.begin(), temp_v.end(), v.begin());
	}
	else
	{
		float avg = (float)sum / (float)cnt;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				float temp = (float)v[i][j];
				if (temp == 0) continue;
				if (temp < avg) v[i][j] += 1;
				else if(temp > avg) v[i][j] -= 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		int tt;
		for (int j = 0; j < m; j++)
		{
			cin >> tt;
			temp.push_back(tt);
		}
		v[i] = temp;
	}

	temp_v.assign(v.size(), vector<int>(m));

	for (int i = 0; i < t; i++)
	{
		cin >> x >> d >> k;

		for (int j = x; j <= n; j += x)
		{
			int z = j - 1;
			if (d == 0)
			{
				rotate(v[z].begin(), v[z].end() - k, v[z].end());
			}
			else
			{
				rotate(v[z].begin(), v[z].begin() + k, v[z].end());
			}
		}
		copy(v.begin(), v.end(), temp_v.begin());
		erase();
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret += v[i][j];
		}
	}

	cout << ret << "\n";

	return 0;
}