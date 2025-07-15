#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> board;

int main()
{
	cin >> n >> m;

	board = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}  

	for (int i = 0; i < m; i++)
	{
		int d, s;
		cin >> d >> s;
	}

	return 0;
}