#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<int> dp;

    int dfs(int y, int x, vector<vector<int>>& board)
    {
        if (y >= n) return 0;

        int& ret = dp[y * n + x];
        if (ret != -INF) return ret;

        ret = INF;

        for (int i = 0; i < n; i++)
        {
            if (i == x) continue;

            ret = min(ret, board[y][i] + dfs(y + 1, i, board));
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        n = grid.size();
        dp.assign(n * n, -INF);

        int ret = INF;
        for (int i = 0; i < n; i++)
        {
            ret = min(ret, grid[0][i] + dfs(1, i, grid));
        }

        return ret;
    }
};

int main()
{

    return 0;
}