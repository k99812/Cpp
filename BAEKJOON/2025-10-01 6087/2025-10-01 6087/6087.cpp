#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n, m;
vector<vector<int>> board;
pair<int, int> start, end_;

int main()
{
	cin >> m >> n;
	start = { -1, -1 };

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '.') board[i][j] = 0;
			else if (s[j] == '*') board[i][j] = 1;
			else
			{
				board[i][j] = 2;
				if (start.first == -1) start = { i, j };
				else end_ = { i, j };
			}
		}
	}

	return 0;
}