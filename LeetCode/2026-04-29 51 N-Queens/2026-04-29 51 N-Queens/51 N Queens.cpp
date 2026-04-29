#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
	vector<string> board;
	vector<vector<string>> ret;
	vector<bool> col, right_cross, left_cross;

	int n;

	void dfs(int row)
	{
		if (row == n)
		{
			ret.push_back(board);
			return;
		}

		for (int c = 0; c < n; c++)
		{
			if (col[c] || right_cross[row + c] || left_cross[row - c + n - 1]) continue;

			col[c] = true;
			right_cross[row + c] = true, left_cross[row - c + n - 1] = true;
			board[row][c] = 'Q';

			dfs(row + 1);

			col[c] = false;
			right_cross[row + c] = false, left_cross[row - c + n - 1] = false;
			board[row][c] = '.';
		}
	}

public:
    vector<vector<string>> solveNQueens(int num) 
	{
		n = num;

		col.assign(n, false);
		left_cross.assign(n + n - 1, false);
		right_cross.assign(n + n - 1, false);
		board.assign(n, string(n, '.'));

		dfs(0);

		return ret;
    }
};

int main()
{
	int n;
	cin >> n;

	Solution sol = Solution();

	vector<vector<string>> ret = sol.solveNQueens(n);

	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[0].size(); j++)
		{
			cout << ret[i][j] << "\n";
		}
		cout << "----------------\n";
	}

	return 0;
}