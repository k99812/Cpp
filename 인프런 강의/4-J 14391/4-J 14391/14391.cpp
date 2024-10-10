#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 5;
int n, m, _map[MAX][MAX], ret = -1;
string s;

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			_map[i][j] = s[j] - '0';
		}
	}

	for (int t = 0; t < (1 << n * m); t++)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;
				if ((t & (1 << k)) == 0)
				{
					cnt = cnt * 10 + _map[i][j];
				}else
				{
					sum += cnt;
					cnt = 0;
				}
			}
			sum += cnt;
		}

		for (int j = 0; j < m; j++)
		{
			int cnt = 0;
			for (int i = 0; i < n; i++)
			{
				int k = i * m + j;
				if ((t & (1 << k)) != 0)
				{
					cnt = cnt * 10 + _map[i][j];
				}
				else
				{
					sum += cnt;
					cnt = 0;
				}
			}
			sum += cnt;
		}
		ret = max(ret, sum);
	}
	cout << ret << "\n";
	return 0;
}