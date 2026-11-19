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

    int n, m;
    vector<pair<int, int>> rubber;
    
    struct Node
    {
        int y, x, cost;

        bool operator<(const Node& other) const
        {
            return cost < other.cost;
        }
    };

    vector<vector<int>> bfs(const vector<vector<int>>& grid)
    {
        vector<vector<int>> safe(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    safe[i][j] = 0;
                    q.push({ i, j });
                }
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
                if (safe[ny][nx] != -1) continue;

                safe[ny][nx] = safe[y][x] + 1;
                q.push({ ny, nx });
            }
        }

        return safe;
    }

    int dijkstra(const vector<vector<int>>& safe)
    {
        priority_queue<Node> pq;
        vector<vector<int>> dist(n, vector<int>(m, -1));

        pq.push({ 0, 0, safe[0][0] });
        dist[0][0] = safe[0][0];

        while (pq.size())
        {
            auto [y, x, c] = pq.top();
            pq.pop();

            if (y == n - 1 && x == m - 1) return c;
            if (dist[y][x] != c) continue;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                int nc = min(c, safe[ny][nx]);

                if (dist[ny][nx] < nc)
                {
                    dist[ny][nx] = nc;
                    pq.push({ ny, nx, nc });
                }
            }
        }

        return 0;
    }

public:
    Solution() : n(0), m(0) {}

    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> safe = bfs(grid);

        return dijkstra(safe);
    }
};

int main()
{

	return 0;
}