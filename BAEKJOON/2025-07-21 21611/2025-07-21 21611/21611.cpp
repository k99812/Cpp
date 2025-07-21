#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> board;
pair<int, int> shark;

int main()
{
	cin >> n >> m;

	shark = { (n + 1) / 2, (n + 1) / 2 };
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