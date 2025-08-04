#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int n = 3;
int r, c, k;
vector<vector<int>> arr;

int main()
{
	cin >> r >> c >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	return 0;
}