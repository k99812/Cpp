#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;
    const int dy[2] = { 1, 0 };
    const int dx[2] = { 0, 1 };

    int n, m;
    vector<vector<int>> board, dp;

    int dfs(int y, int x)
    {
        if (y == n - 1 && x == m - 1) return dp[y][x] = board[y][x];

        int& ret = dp[y][x];
        if (dp[y][x] != -1) return ret;

        ret = INF;

        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            ret = min(ret, board[y][x] + dfs(ny, nx));
        }

        return ret;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();
        dp.assign(n, vector<int>(m, -1));

        dfs(0, 0);

        return dp[0][0];
    }
};

int main()
{

	return 0;
}