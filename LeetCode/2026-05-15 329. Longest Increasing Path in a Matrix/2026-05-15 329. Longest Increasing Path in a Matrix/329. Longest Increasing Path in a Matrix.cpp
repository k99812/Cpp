#include<iostream>
#include<algorithm>
#include<vector>

using namespace  std;

class Solution 
{
private:
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<int>> matrix;
    vector<vector<int>> dp;

    int dfs(int y, int x)
    {
        int& ret = dp[y][x];
        if (ret != -1) return ret;

        ret = 1;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (matrix[ny][nx] <= matrix[y][x]) continue;

            ret = max(ret, dfs(ny, nx) + 1);
        }

        return ret;
    }

public:
    Solution() : n(0), m(0)
    {
       
    }

    int longestIncreasingPath(vector<vector<int>>& input) 
    {
        matrix = input;
        n = input.size(), m = input[0].size();

        dp.assign(n, vector<int>(m, -1));

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ret = max(ret, dfs(i, j));
            }
        }

        return ret;
    }
};

int main()
{
    vector<vector<int>> matrix = 
    {
        { 9, 9, 4},
        { 6, 6, 8},
        { 2, 1, 1}
    };

    Solution sol = Solution();

    cout << sol.longestIncreasingPath(matrix) << "\n";

	return 0;
}