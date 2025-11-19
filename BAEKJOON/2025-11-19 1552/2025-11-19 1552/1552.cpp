#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<vector<char>> board;

int main()
{
	cin >> n;

	board = vector<vector<char>>(n, vector<char>(n));

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = s[j];
		}
	}

	return 0;
}