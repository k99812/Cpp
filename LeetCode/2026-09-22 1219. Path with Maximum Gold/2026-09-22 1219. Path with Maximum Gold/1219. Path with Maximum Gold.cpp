#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m, ret;
    vector<vector<int>> board;

    void dfs(int y, int x, int sum)
    {
        ret = max(ret, sum);

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (board[ny][nx] == 0) continue;

            int ori = board[ny][nx];
            board[ny][nx] = 0;
            dfs(ny, nx, sum + ori);
            board[ny][nx] = ori;
        }
    }

public:
    Solution() : n(0), m(0), ret(0)
    {

    }

    int getMaximumGold(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        board = move(grid);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0) continue;

                int ori = board[i][j];
                board[i][j] = 0;
                dfs(i, j, ori);
                board[i][j] = ori;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}