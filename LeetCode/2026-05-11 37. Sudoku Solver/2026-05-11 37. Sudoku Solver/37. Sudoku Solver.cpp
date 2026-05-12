#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
private:
    
    const int SIZE = 3;

    int n, m;
    vector<vector<char>>* board;

#define ptr_board (*board)

    bool check(int y, int x, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (ptr_board[i][x] == c) return false;
            if (ptr_board[y][i] == c) return false;
            if (ptr_board[SIZE * (y / SIZE) + i / SIZE][SIZE * (x / SIZE) + i % SIZE] == c) return false;
        }
        
        return true;
    }

    bool dfs(int idx)
    {
        if (idx == 81) return true;

        int y = idx / 9, x = idx % 9;

        if (ptr_board[y][x] != '.') return dfs(idx + 1);

        for (int i = 1; i <= 9; i++)
        {
            if (check(y, x, i + '0'))
            {
                ptr_board[y][x] = i + '0';
                if(dfs(idx + 1)) return true;
                ptr_board[y][x] = '.';
            }
        }

        return false;
    }

public:
    Solution() : board(nullptr), n(9), m(9)
    {

    }

    void solveSudoku(vector<vector<char>>& input)
    {
        board = &input;
        dfs(0);
    }
};

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution sol = Solution();
    sol.solveSudoku(board);

	return 0;
}