#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    const int PACIFIC = 1;
    const int ATLANTIC = 2;

    int n, m;
    vector<vector<int>> board, visited;

    void bfs(queue<pair<int, int>>& q, int code)
    {
        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if ((visited[ny][nx] & code) || board[ny][nx] < board[y][x]) continue;

                visited[ny][nx] |= code;
                q.push({ ny, nx });
            }
        }
    }

public:
    Solution() : n(0), m(0)
    {

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        board = move(heights);
        n = board.size(), m = board[0].size();

        visited.assign(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int y = 0; y < n; y++) 
        {
            visited[y][0] |= PACIFIC; 
            q.push({ y, 0 });
        }

        for (int x = 0; x < m; x++) 
        {
            if (!(visited[0][x] & PACIFIC)) 
            { 
                visited[0][x] |= PACIFIC; 
                q.push({ 0, x }); 
            }
        }

        bfs(q, PACIFIC);

        for (int y = 0; y < n; y++) 
        {
            visited[y][m - 1] |= ATLANTIC; 
            q.push({ y, m - 1 });
        }
        for (int x = 0; x < m; x++) 
        {
            if (!(visited[n - 1][x] & ATLANTIC)) 
            { 
                visited[n - 1][x] |= ATLANTIC;
                q.push({ n - 1, x }); 
            }
        }
        bfs(q, ATLANTIC);
        
        vector<vector<int>> ret;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (visited[y][x] == 3)
                {
                    ret.push_back({ y, x });
                }
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}