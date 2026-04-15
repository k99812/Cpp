#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, g, r;
vector<vector<int>> board;

int main()
{
	cin >> n >> m >> g >> r;

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	return 0;
}