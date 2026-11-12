#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int MOD = 1e9 + 7;
    const int dy[2] = { 1, 0 };
    const int dx[2] = { 0, 1 };

    int n, m;
    vector<vector<int>> dp;

    int dfs(int y, int x, int rem, const vector<vector<int>>& grid, int k)
    {
        int next_rem = (rem + grid[y][x]) % k;

        if (y == n - 1 && x == m - 1)
        {
            return next_rem == 0 ? 1 : 0;
        }

        int& ret = dp[y * m + x][rem];
        if (ret != -1) return ret;

        ret = 0;

        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            ret = (ret + dfs(ny, nx, next_rem, grid, k)) % MOD;
        }

        return ret;
    }

public:
    Solution() : n(0), m(0) {}

    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n * m, vector<int>(k, -1));

        return dfs(0, 0, 0, grid, k);
    }
};

int main()
{

	return 0;
}