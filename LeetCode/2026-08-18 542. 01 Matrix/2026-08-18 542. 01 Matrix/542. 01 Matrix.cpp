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
    vector<vector<int>> board;

    vector<vector<int>> bfs()
    {
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({ i, j });
                }
            }
        }

        while (q.size())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (dist[ny][nx] != -1) continue;

                dist[ny][nx] = dist[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        return dist;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        board = move(mat);
        n = board.size(), m = board[0].size();

        return bfs();
    }
};

int main()
{

	return 0;
}