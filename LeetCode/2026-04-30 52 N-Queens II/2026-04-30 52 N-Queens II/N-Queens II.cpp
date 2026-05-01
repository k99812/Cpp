#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
	int n, ret = 0;
	vector<bool> col, right_cross, left_cross;

	void dfs(int r)
	{
		if (r == n)
		{
			ret++;
			return;
		}

		for (int c = 0; c < n; c++)
		{
			if (col[c] || right_cross[r + c] || left_cross[r - c + n - 1]) continue;

			col[c] = true;
			right_cross[r + c] = true, left_cross[r - c + n - 1] = true;

			dfs(r + 1);

			col[c] = false;
			right_cross[r + c] = false, left_cross[r - c + n - 1] = false;
		}
	}

public:
	Solution() : n(0)
	{

	}

	int totalNQueens(int num) 
	{
		n = num;
		ret = 0;
		
		col.assign(n, false);
		right_cross.assign(n + n - 1, false);
		left_cross.assign(n + n - 1, false);

		dfs(0);

		return ret;
	}
};

int main()
{
	int n;
	cin >> n;

	Solution sol = Solution();

	int ret = sol.totalNQueens(n);

	cout << ret << "\n";

	return 0;
}