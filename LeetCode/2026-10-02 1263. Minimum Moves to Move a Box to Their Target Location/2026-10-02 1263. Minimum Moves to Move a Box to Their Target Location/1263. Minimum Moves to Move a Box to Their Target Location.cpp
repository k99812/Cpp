#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int player_y, player_x, box_y, box_x;
};

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<char>> board;

    int bfs()
    {
        vector<vector<vector<vector<int>>>> visited(n, vector<vector<vector<int>>>(m, 
            vector<vector<int>>(n, vector<int>(m, -1))));
        deque<Node> dq;

        Node temp;
        pair<int, int> target;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'B')
                {
                    temp.box_y = i;
                    temp.box_x = j;
                }
                else if (board[i][j] == 'S')
                {
                    temp.player_y = i;
                    temp.player_x = j;
                }
                else if (board[i][j] == 'T')
                {
                    target = { i, j };
                }
            }
        }

        dq.push_back(temp);
        visited[temp.player_y][temp.player_x][temp.box_y][temp.box_x] = 0;

        while (dq.size())
        {
            auto [py, px, by, bx] = dq.front();
            dq.pop_front();

            if (by == target.first && bx == target.second) return visited[py][px][by][bx];

            for (int i = 0; i < 4; i++)
            {
                int n_py = py + dy[i], n_px = px + dx[i];

                if (n_py < 0 || n_px < 0 || n_py >= n || n_px >= m) continue;
                if (board[n_py][n_px] == '#') continue;

                if (n_py == by && n_px == bx)
                {
                    int n_by = by + dy[i], n_bx = bx + dx[i];

                    if (n_by < 0 || n_bx < 0 || n_by >= n || n_bx >= m) continue;
                    if (board[n_by][n_bx] == '#' || visited[n_py][n_px][n_by][n_bx] != -1) continue;

                    visited[n_py][n_px][n_by][n_bx] = visited[py][px][by][bx] + 1;
                    dq.push_back({ n_py, n_px, n_by, n_bx });
                }
                else
                {
                    if (visited[n_py][n_px][by][bx] == -1)
                    {
                        visited[n_py][n_px][by][bx] = visited[py][px][by][bx];
                        dq.push_front({ n_py, n_px, by, bx });
                    }
                }
            }
        }

        return -1;
    }

public:
    Solution() : n(0), m(0)
    {

    }

    int minPushBox(vector<vector<char>>& grid) 
    {
        board = move(grid);
        n = board.size(), m = board[0].size();

        return bfs();
    }
};

int main()
{

	return 0;
}