#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    vector<vector<int>> board;

    int bfs()
    {
        queue<pair<int, int>> q;

        int cnt_1 = 0, cnt_2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 1)
                {
                    cnt_1++;
                }
                else if (board[i][j] == 2)
                {
                    cnt_2++;
                    q.push({ i, j });
                }
            }
        }

        if (cnt_1 == 0) return 0;

        int time = 0;
        while (q.size())
        {
            int s = q.size();
            while (s--)
            {
                int y = q.front().first, x = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i], nx = x + dx[i];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                    if (board[ny][nx] == 1)
                    {
                        cnt_1--;
                        board[ny][nx] = 2;
                        q.push({ ny, nx });
                    }
                }
            }

            if(q.size()) time++;
        }

        if (cnt_1 > 0) return -1;

        return time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size();
        m = board[0].size();

        return bfs();
    }
};

int main()
{

	return 0;
}