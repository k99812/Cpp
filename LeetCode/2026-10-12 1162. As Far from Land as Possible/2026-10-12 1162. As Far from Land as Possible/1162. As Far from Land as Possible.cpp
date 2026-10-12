#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int bfs(int n, queue<pair<int, int>>& q, vector<vector<int>>& visited, const vector<vector<int>>& grid)
    {
        int ret = 0;

        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (grid[ny][nx] == 1 || visited[ny][nx] != -1) continue;

                visited[ny][nx] = visited[y][x] + 1;
                ret = max(ret, visited[ny][nx]);
                q.push({ ny, nx });
            }
        }

        return ret;
    }

public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n = grid.size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(n, -1));

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    cnt++;
                    q.push({ i, j });
                    visited[i][j] = 0;
                }
            }
        }

        if (cnt == n * n || cnt == 0) return -1;

        return bfs(n, q, visited, grid);
    }
};

int main()
{

	return 0;
}