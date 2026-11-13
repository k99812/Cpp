#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = INT32_MAX;
    const int MOD = 1e9 + 7;
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m, maxMove;
    vector<vector<int>> dp;

    int dfs(int y, int x, int move)
    {
        if (y < 0 || x < 0 || y >= n || x >= m) return 1;

        if (move >= maxMove) return 0;

        int& ret = dp[y * m + x][move];
        if (ret != -1) return ret;

        ret = 0;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            ret = (ret + dfs(ny, nx, move + 1)) % MOD;
        }

        return ret;
    }

public:
    Solution() : n(0), m(0), maxMove(0) {}

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        this->n = m;
        this->m = n;
        this->maxMove = maxMove;

        dp.assign(n * m, vector<int>(maxMove, -1));
        
        return dfs(startRow, startColumn, 0);
    }
};

int main()
{

	return 0;
}