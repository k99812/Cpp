#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, m;
    string str;
    vector<vector<char>> board;

    bool dfs(int y, int x, int idx)
    {
        if (idx == str.size() - 1) return true;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i], nx = x + dx[i], nidx = idx + 1;

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (board[ny][nx] != str[nidx]) continue;

            char temp = board[ny][nx];

            board[ny][nx] = '*';
            if (dfs(ny, nx, idx + 1)) return true;
            board[ny][nx] = temp;
        }

        return false;
    }

public:
    Solution() : n(0), m(0), str()
    {

    }

    bool exist(vector<vector<char>>& input_map, string word) 
    {
        board = move(input_map);
        str = move(word);

        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] != str[0]) continue;

                char temp = board[i][j];

                board[i][j] = '*';
                if (dfs(i, j, 0)) return true;
                board[i][j] = temp;
            }
        }

        return false;
    }
};

int main()
{

	return 0;
}