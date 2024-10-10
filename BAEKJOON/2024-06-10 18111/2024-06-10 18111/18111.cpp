#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4

using namespace std;

int n, m, b, a[MAX_NUM][MAX_NUM], ret = 1e9, hig;

int main()
{
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	for (int h = 0; h <= 256; h++)
	{
		int dig = 0, build = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] - h > 0)
				{
					dig += a[i][j] - h;
				}
				else if(a[i][j] - h < 0)
				{
					build += h - a[i][j];
				}
			}
		}

		if (dig + b >= build)
		{
			int time = dig * 2 + build;
			if (ret >= time)
			{
				ret = time;
				hig = h;
			}
		}
	}
	
	cout << ret << " " << hig;

	return 0;
}