#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    const int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

    int n;
    vector<vector<int>> board, dist;

    int bfs()
    {
        queue<pair<int, int>> q;

        if (board[0][0] == 0)
        {
            q.push({ 0, 0 });
            dist[0][0] = 1;
        }
        
        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (dist[ny][nx] != -1 || board[ny][nx] != 0) continue;

                dist[ny][nx] = dist[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        return dist[n - 1][n - 1];
    }

public:
    Solution() : n(0)
    {

    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size();

        dist.assign(n, vector<int>(n, -1));

        return bfs();
    }
};

int main()
{

	return 0;
}