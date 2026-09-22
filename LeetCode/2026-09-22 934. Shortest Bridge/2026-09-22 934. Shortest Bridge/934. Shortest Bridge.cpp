#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n;
    vector<vector<int>> board;

    void dfs(int y, int x, queue<pair<int, int>>& q)
    {
        board[y][x] = 2;
        q.push({ y, x });

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (board[ny][nx] == 0 || board[ny][nx] == 2) continue;

            dfs(ny, nx, q);
        }
    }

    int bfs(queue<pair<int, int>>& q)
    {
        int ret = 0;
        while (q.size())
        {
            int size = q.size();

            while (size--)
            {
                auto [cy, cx] = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ny = cy + dy[i], nx = cx + dx[i];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if (board[ny][nx] == 1) return ret;

                    if (board[ny][nx] == 0)
                    {
                        board[ny][nx] = 2;
                        q.push({ ny, nx });
                    }
                }
            }
            ret++;
        }

        return -1;
    }

public:
    Solution() : n(0)
    {

    }

    int shortestBridge(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size();
        queue<pair<int, int>> q;
        
        bool found = false;
        for (int i = 0; i < n && !found; i++)
        {
            for (int j = 0; j < n && !found; j++)
            {
                if (board[i][j] == 0) continue;
                dfs(i, j, q);
                found = true;
            }
        }

        return bfs(q);
    }
};

int main()
{

	return 0;
}