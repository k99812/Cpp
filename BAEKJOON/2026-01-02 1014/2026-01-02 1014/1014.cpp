#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int c, n, m;
vector<vector<int>> board;

int main()
{
	cin >> c;

	while (c--)
	{
		cin >> n >> m;

		board = vector<vector<int>>(n, vector<int>(m));

		for (int i = 0; i < n; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < m; j++)
			{
				board[i][j] = str[j] == '.' ? 0 : 1;
			}
		}
	}

	return 0;
}