#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int lines[6][4] = {
    {0, 2, 5, 7},   // ↘ 방향 위
    {0, 3, 6, 10},  // ↙ 방향 위
    {1, 2, 3, 4},   // ㅡ 방향 위
    {1, 5, 8, 11},  // ↘ 방향 아래
    {4, 6, 9, 11},  // ↙ 방향 아래
    {7, 8, 9, 10}   // ㅡ 방향 아래
};

int n = 5, m = 9;
vector<bool> used(12);
vector<string> board;
vector<pair<int, int>> pos;

bool check() 
{
    for (int i = 0; i < 6; i++) 
    {
        int sum = 0;
        for (int j = 0; j < 4; j++) 
        {
            int idx = lines[i][j];
            int y = pos[idx].first, x = pos[idx].second;

            sum += (board[y][x] - 'A' + 1);
        }

        if (sum != 26) return false;
    }

    return true;
}

void dfs(int idx) 
{
    if (idx == 12) 
    {
        if (check()) 
        {
            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < m; j++) 
                {
                    cout << board[i][j];
                }
                cout << "\n";
            }
            exit(0);
        }
        return;
    }

    int y = pos[idx].first, x = pos[idx].second;

    if (board[y][x] != 'x') 
    {
        dfs(idx + 1);
        return;
    }

    for (int i = 0; i < 12; i++)
    {
        if (used[i]) continue;

        used[i] = true;
        board[y][x] = (char)('A' + i);

        dfs(idx + 1);

        board[y][x] = 'x';
        used[i] = false;
    }
}

int main() 
{
    board = vector<string>(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> board[i];
        for (int j = 0; j < m; j++) 
        {
            if (board[i][j] == '.')  continue;
            pos.push_back({ i, j });

            if (board[i][j] != 'x')
            {
                used[board[i][j] - 'A'] = true;
            }
        }
    }

    dfs(0);

    return 0;
}