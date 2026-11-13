#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;
    const int dy[4] = { 1, 0, -1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n;
    vector<vector<int>> dp;

    int dfs(int y1, int x1, int y2, const vector<vector<int>>& grid)
    {
        int x2 = y1 + x1 - y2;

        if (y1 >= n || x1 >= n || y2 >= n || x2 >= n) return -INF;
        if (grid[y1][x1] == -1 || grid[y2][x2] == -1) return -INF;

        if (y1 == n - 1 && x1 == n - 1) return grid[y1][x1];

        int& ret = dp[y1 * n + x1][y2];
        if (ret != -1) return ret;

        ret = -INF;

        int cherries = grid[y1][x1];
        if (y1 != y2) 
        {
            cherries += grid[y2][x2];
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int ny1 = y1 + dy[i], nx1 = x1 + dx[i];
                int ny2 = y2 + dy[j]; 

                ret = max(ret, cherries + dfs(ny1, nx1, ny2, grid));
            }
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    int cherryPickup(vector<vector<int>>& grid) 
    {
        n = grid.size();
        dp.assign(n * n, vector<int>(n, -1));

        return max(0, dfs(0, 0, 0, grid));
    }
};

int main()
{

	return 0;
}