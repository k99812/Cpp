#include<iostream>
#include<algorithm>
#include<string>

#define MAX_NUM 12

using namespace std;

int n, m, dist[MAX_NUM];
char a[MAX_NUM][MAX_NUM];

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = s[j];
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}