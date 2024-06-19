#include<iostream>
#include<algorithm>

#define MAX_NUM 500 + 4

using namespace std;

int n, a[MAX_NUM][MAX_NUM];

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	return 0;
}
