#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct INFO
{
    int y, x, keys;
};

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m, key_num;
    pair<int, int> start;
    vector<string> board;

    int bfs()
    {
        vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(1 << key_num, -1)));
        queue<INFO> q;

        q.push({ start.first, start.second, 0 });
        visited[start.first][start.second][0] = 0;

        while (q.size())
        {
            int y = q.front().y, x = q.front().x;
            int now_keys = q.front().keys;
            q.pop();

            if (now_keys == (1 << key_num) - 1) return visited[y][x][now_keys];

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i], nx = x + dx[i];
                int next_keys = now_keys;

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (board[ny][nx] == '#') continue;

                if (islower(board[ny][nx]))
                {
                    next_keys |= (1 << (board[ny][nx] - 'a'));
                }

                if (isupper(board[ny][nx]) && !(next_keys & (1 << (board[ny][nx] - 'A')))) continue;

                
                if (visited[ny][nx][next_keys] != -1) continue;

                visited[ny][nx][next_keys] = visited[y][x][now_keys] + 1;
                q.push({ ny, nx, next_keys });
            }
        }

        return -1;
    }

public:
    Solution() : n(0), m(0), key_num(0)
    {

    }

    int shortestPathAllKeys(vector<string>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        board = move(grid);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '@')
                {
                    start = { i, j };
                }
                else if (islower(board[i][j]))
                {
                    key_num++;
                }
            }
        }

        return bfs();
    }
};

int main()
{

	return 0;
}