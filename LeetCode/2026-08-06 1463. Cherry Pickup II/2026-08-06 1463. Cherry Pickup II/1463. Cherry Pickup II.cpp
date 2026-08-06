#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int dx[3] = { -1, 0, 1 };

    int n, m;
    vector<vector<int>> board;
    vector<vector<vector<int>>> dp;

    int dfs(int y, int x1, int x2)
    {
        if (y == n) return 0;

        int& ret = dp[y][x1][x2];
        if (ret != -1) return ret;

        ret = 0;

        int now_cherry = (x1 == x2) ? board[y][x1] : board[y][x1] + board[y][x2];

        for (int i = 0; i < 3; i++)
        {
            int ny = y + 1, nx1 = x1 + dx[i];

            if (nx1 < 0 || nx1 >= m) continue;

            for (int j = 0; j < 3; j++)
            {
                int nx2 = x2 + dx[j];

                if (nx2 < 0 || nx2 >= m) continue;

                ret = max(ret, dfs(ny, nx1, nx2) + now_cherry);
            }
        }

        return ret;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int cherryPickup(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return dfs(0, 0, m - 1);
    }
};

int main()
{

	return 0;
}