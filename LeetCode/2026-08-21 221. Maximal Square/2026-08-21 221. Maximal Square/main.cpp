#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, m, max_size;
    vector<vector<int>> board, dp;
    
    int dfs(int y, int x)
    {
        if (y < 0 || x < 0 || y >= n || x >= m) return 0;

        int& ret = dp[y][x];
        if (ret != -1) return ret;

        ret = 0;

        if (board[y][x] == 0) return ret;

        int right = dfs(y, x + 1);
        int down = dfs(y + 1, x);
        int diag = dfs(y + 1, x + 1);

        ret = 1 + min({ right, down, diag });

        max_size = max(max_size, ret);

        return ret;
    }

public:
    Solution() : n(0), m(0), max_size(0)
    {

    }

    int maximalSquare(vector<vector<char>>& matrix) 
    {
        n = matrix.size(), m = matrix[0].size();
        board.assign(n, vector<int>(m, 0));
        dp.assign(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = matrix[i][j] - '0';
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(i, j);
            }
        }

        return max_size * max_size;
    }
};

int main() 
{

    return 0;
}