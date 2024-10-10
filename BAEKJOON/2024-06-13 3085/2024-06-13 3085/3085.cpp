#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, ret;
char a[54][54];

void countRow()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		char prev = a[i][0];
		for (int j = 1; j < n; j++)
		{
			if (prev == a[i][j])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			ret = max(ret, cnt);
			prev = a[i][j];
		}
	}
}

void countColumn()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		char prev = a[0][i];
		for (int j = 1; j < n; j++)
		{
			if (prev == a[j][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			ret = max(ret, cnt);
			prev = a[j][i];
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			a[i][j] = s[j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			swap(a[i][j], a[i][j + 1]);

			countRow();
			countColumn();

			swap(a[i][j], a[i][j + 1]);

			swap(a[j][i], a[j + 1][i]);

			countRow();
			countColumn();

			swap(a[j][i], a[j + 1][i]);
		}
	}

	cout << ret << "\n";

	return 0;
}