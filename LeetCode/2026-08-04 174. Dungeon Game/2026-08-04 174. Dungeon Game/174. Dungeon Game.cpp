#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int INF = 1e9;
    const int dy[2] = { 0, 1 };
    const int dx[2] = { 1, 0 };

    int n, m;
    vector<vector<int>> board, dp;

    int dfs(int y, int x)
    {
        if (y == n - 1 && x == m - 1)
        {
            return max(1, 1 - board[y][x]);
        }

        int& ret = dp[y][x];
        if (ret != INF) return ret;

        ret = 0;

        int next_need = INF;
        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

            next_need = min(next_need, dfs(ny, nx));
        }

        return ret = max(1, next_need - board[y][x]);
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        board = move(dungeon);
        n = board.size(), m = board[0].size();
        dp.assign(n, vector<int>(m, INF));

        return dfs(0, 0);
    }
};

int main()
{

	return 0;
}