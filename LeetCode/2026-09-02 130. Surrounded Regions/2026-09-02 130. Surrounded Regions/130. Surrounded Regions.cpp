#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

public:
    void solve(vector<vector<char>>& board)
    {
        int n = board.size(), m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O')
            {
                visited[i][0] = true;
                q.push({ i, 0 });
            }
            
            if (visited[i][m - 1] == false && board[i][m - 1] == 'O')
            {
                visited[i][m - 1] = true;
                q.push({ i, m - 1 });
            }
        }

        for (int j = 0; j < m; j++)
        {
            if (board[0][j] == 'O')
            {
                visited[0][j] = true;
                q.push({ 0, j });
            }
            
            if (visited[n - 1][j] == false && board[n - 1][j] == 'O')
            {
                visited[n - 1][j] = true;
                q.push({ n - 1, j });
            }
        }

        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx] || board[ny][nx] == 'X') continue;

                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (board[y][x] == 'X' || visited[y][x]) continue;

                board[y][x] = 'X';
            }
        }
    }
};

int main()
{

	return 0;
}