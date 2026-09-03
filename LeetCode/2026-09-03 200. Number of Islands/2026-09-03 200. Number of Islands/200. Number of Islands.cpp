#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<char>> board;

    void bfs(int y, int x)
    {
        queue<pair<int, int>> q;
        q.push({ y, x });
        board[y][x] = '0';

        while (q.size())
        {
            auto [cy, cx] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i], nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (board[ny][nx] == '0') continue;

                q.push({ ny, nx });
                board[ny][nx] = '0';
            }
        }
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int numIslands(vector<vector<char>>& grid) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '0') continue;

                ret++;
                bfs(i, j);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}