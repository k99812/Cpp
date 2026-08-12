#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

class Solution 
{
    const int INF = 1e9;
    const int dy[5] = { 0, 0, 0, 1, -1 };
    const int dx[5] = { 0, 1, -1, 0, 0 };

    int n, m;
    vector<vector<int>> board, cost;

    int bfs()
    {
        deque<pair<int, int>> dq;
        cost[0][0] = 0;
        dq.push_front({ 0, 0 });

        while (dq.size())
        {
            int y = dq.front().first, x = dq.front().second;
            dq.pop_front();

            if (y == n - 1 && x == m - 1) break;

            for (int i = 1; i <= 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];
                int nc = board[y][x] == i ? 0 : 1;

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                if (cost[ny][nx] > cost[y][x] + nc)
                {
                    cost[ny][nx] = cost[y][x] + nc;

                    if (nc == 0)
                    {
                        dq.push_front({ ny, nx });
                    }
                    else
                    {
                        dq.push_back({ ny, nx });
                    }
                } 
            }
        }

        return cost[n - 1][m - 1];
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int minCost(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();
        cost.assign(n, vector<int>(m, INF));

        return bfs();
    }
};

int main()
{

	return 0;
}