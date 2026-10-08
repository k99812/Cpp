#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    void bfs(int n, int m, int s, int e, const vector<vector<int>>& board, vector<vector<int>>& visited)
    {
        queue<pair<int, int>> q;

        q.push({ s, e });
        visited[s][e] = true;

        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx] || board[ny][nx]) continue;

                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }
    }

public:
    int regionsBySlashes(vector<string>& grid) 
    {
        int n = grid.size() * 3, m = grid[0].size() * 3;
        vector<vector<int>> board(n, vector<int>(m, 0));

        for (int i = 0; i < n / 3; i++)
        {
            for (int j = 0; j < m / 3; j++)
            {
                int y = i * 3, x = j * 3;

                if (grid[i][j] == '\\')
                {
                    board[y][x] = 1;
                    board[y + 1][x + 1] = 1;
                    board[y + 2][x + 2] = 1;
                }
                else if (grid[i][j] == '/')
                {
                    board[y][x + 2] = 1;
                    board[y + 1][x + 1] = 1;
                    board[y + 2][x] = 1;
                }
            }
        }
        
        int ret = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visited[i][j] || board[i][j] == 1) continue;

                ret++;
                bfs(n, m, i, j, board, visited);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}