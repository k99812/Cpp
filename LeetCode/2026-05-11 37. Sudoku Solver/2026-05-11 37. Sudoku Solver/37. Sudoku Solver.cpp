#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
private:
    int n, m;
    vector<vector<char>>* board;

    void dfs()
    {
        
    }

public:
    Solution() : board(nullptr), n(9), m(9)
    {

    }

    void solveSudoku(vector<vector<char>>& input)
    {
        *board = input;
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