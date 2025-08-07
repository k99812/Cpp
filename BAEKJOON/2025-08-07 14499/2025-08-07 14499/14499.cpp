#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, x, y, k;
vector<vector<int>> board;

int go(int command)
{

}

int main()
{
	cin >> n >> m >> x >> y >> k;

	board = vector<vector<int>>(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int d;
		cin >> d;
		cout << go(d) << "\n";
	}

	return 0;
}