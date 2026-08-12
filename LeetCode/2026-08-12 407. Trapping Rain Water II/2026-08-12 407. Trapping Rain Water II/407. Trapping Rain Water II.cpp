#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int y, x, height;

    bool operator<(const Node& other) const
    {
        return height > other.height;
    }
};

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<int>> board, visited;

    int bfs()
    {
        priority_queue<Node> pq;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    pq.push({ i, j, board[i][j] });
                    visited[i][j] = 1;
                }
            }
        }

        int water = 0;
        while (pq.size())
        {
            int cy = pq.top().y, cx = pq.top().x;
            int ch = pq.top().height;
            pq.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i], nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
                if (visited[ny][nx]) continue;

                int nh = board[ny][nx];

                if (ch > nh)
                {
                    water += ch - nh;
                }

                visited[ny][nx] = true;
                pq.push({ ny, nx, max(ch, nh) });
            }
        }

        return water;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int trapRainWater(vector<vector<int>>& heightMap) 
    {
        board = move(heightMap);
        n = board.size(), m = board[0].size();
        visited.assign(n, vector<int>(m, 0));

        return bfs();
    }
};

int main()
{

	return 0;
}