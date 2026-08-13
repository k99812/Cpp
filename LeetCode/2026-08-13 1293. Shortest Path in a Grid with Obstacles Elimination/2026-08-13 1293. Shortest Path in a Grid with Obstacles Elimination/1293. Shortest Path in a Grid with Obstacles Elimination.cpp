#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int y, x, k;
};

class Solution 
{
    const int INF = 1e9;
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<int>> board;

    int bfs(int k)
    {
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(k + 1, INF)));
        queue<Node> q;

        q.push({ 0, 0, 0 });
        visited[0][0][0] = 0;

        while (q.size())
        {
            int cy = q.front().y, cx = q.front().x;
            int ck = q.front().k;
            q.pop();

            if (cy == n - 1 && cx == m - 1) return visited[cy][cx][ck];

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i], nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                int nk = ck + board[ny][nx];

                if (nk > k) continue;

                if (visited[ny][nx][nk] != INF) continue;

                visited[ny][nx][nk] = visited[cy][cx][ck] + 1;
                q.push({ ny, nx, nk });
            }
        }

        return -1;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();

        return bfs(k);
    }
};

int main()
{

	return 0;
}