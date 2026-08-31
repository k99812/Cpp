#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, m;
    vector<vector<char>> original, rotating;

    void rotate()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotating[j][n - 1 - i] = original[i][j];
            }
        }
    }

    void gravity()
    {
        for (int i = 0; i < n; i++)
        {
            int empty = m - 1;
            for (int j = m - 1; j >= 0; j--)
            {
                if (original[i][j] == '*')
                {
                    empty = j - 1;
                }
                else if (original[i][j] == '#')
                {
                    original[i][j] = '.';
                    original[i][empty] = '#';
                    empty--;
                }
            }
        }
    }

public:
    Solution() : n(0), m(0)
    {

    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) 
    {
        original = move(boxGrid);
        n = original.size(), m = original[0].size();
        rotating.assign(m, vector<char>(n, '.'));

        gravity();
        rotate();

        return rotating;
    }
};

int main()
{
    Solution sol = Solution();

    vector<vector<char>> board = { {'#', '.', '*', '.'} ,
        {'#', '#', '*', '.'}};

    vector<vector<char>> ret = sol.rotateTheBox(board);
    for (const vector<char>& v : ret)
    {
        for (const char c : v)
        {
            cout << c << " ";
        }
        cout << "\n";
    }

	return 0;
}