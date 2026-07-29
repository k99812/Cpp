#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    // dead: 0, alive: 1, future_dead: 2, future_alive: 3
    const int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    const int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                int& state = board[i][j];

                for (int d = 0; d < 8; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

                    if (board[ny][nx] == 1 || board[ny][nx] == 2) cnt++;
                }

                if (state)
                {
                    if (cnt < 2 || cnt > 3)
                    {
                        state = 2;
                    }
                }
                else
                {
                    if (cnt == 3)
                    {
                        state = 3;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 2) board[i][j] = 0;
                else if (board[i][j] == 3) board[i][j] = 1;
            }
        }
    }
};

int main()
{

	return 0;
}