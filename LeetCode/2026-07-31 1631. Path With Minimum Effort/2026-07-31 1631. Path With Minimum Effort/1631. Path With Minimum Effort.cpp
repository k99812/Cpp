#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

struct Info
{
    int y, x, effort;

    bool operator<(const Info& other) const
    {
        return effort > other.effort;
    }
};

class Solution 
{
    const int INF = 1e9;
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<int>> board, dist;

    void dijkstra()
    {
        priority_queue<Info> pq;
        pq.push({ 0, 0, 0 });
        dist[0][0] = 0;

        while (pq.size())
        {
            int y = pq.top().y, x = pq.top().x;
            int c = pq.top().effort;
            pq.pop();

            if (c != dist[y][x]) continue;

            if (y == n - 1 && x == m - 1) return;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                int nc = max(c, abs(board[ny][nx] - board[y][x]));

                if (dist[ny][nx] > nc)
                {
                    dist[ny][nx] = nc;
                    pq.push({ ny, nx, nc });
                }
            }
        }
    }

    bool bfs(int mid)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        
        q.push({ 0, 0 });
        visited[0][0] = true;

        while (q.size())
        {
            int y = q.front().first, x = q.front().second;
            q.pop();

            if (y == n - 1 && x == m - 1) return true;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx] || abs(board[ny][nx] - board[y][x]) > mid) continue;

                visited[ny][nx] = true;
                q.push({ ny, nx });
            }
        }

        return false;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        board = move(heights);
        n = board.size(), m = board[0].size();
        dist.assign(n, vector<int>(m, INF));

        /*
        dijkstra();

        return dist[n - 1][m - 1];
        */

        int left = 0, right = (int)1e6, ret = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (bfs(mid))
            {
                ret = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}