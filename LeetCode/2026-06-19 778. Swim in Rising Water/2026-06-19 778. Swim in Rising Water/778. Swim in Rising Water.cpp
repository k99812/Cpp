#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct INFO
{
    int y, x, cost;

    bool operator<(const INFO& other) const 
    {
        return cost > other.cost;
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
        priority_queue<INFO> pq;
        dist.assign(n, vector<int>(m, INF));

        dist[0][0] = board[0][0];
        pq.push({ 0, 0, board[0][0] });

        while (pq.size())
        {
            int y = pq.top().y, x = pq.top().x, now_cost = pq.top().cost;
            pq.pop();

            if (dist[y][x] != now_cost) continue;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                int next_cost = max(now_cost, board[ny][nx]);

                if (dist[ny][nx] > next_cost)
                {
                    dist[ny][nx] = next_cost;
                    pq.push({ ny, nx, next_cost });
                }
            }
        }
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int swimInWater(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size();
        m = board[0].size();

        dijkstra();

        return dist[n - 1][m - 1];
    }
};

int main()
{

	return 0;
}