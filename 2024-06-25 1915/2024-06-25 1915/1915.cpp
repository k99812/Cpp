#include<iostream>
#include<algorithm>
#include<string>

#define MAX_NUM 1000 + 4

using namespace std;

int n, m, a[MAX_NUM][MAX_NUM], ret;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = s[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j])
			{
				a[i][j] = min(min(a[i][j - 1], a[i - 1][j]), a[i - 1][j - 1]) + 1;
				ret = max(a[i][j], ret);
			}
		}
	}

	cout << ret * ret << "\n";

	return 0;
}