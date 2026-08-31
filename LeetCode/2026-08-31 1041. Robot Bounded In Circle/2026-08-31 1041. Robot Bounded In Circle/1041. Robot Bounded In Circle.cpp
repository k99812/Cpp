#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int dy[4] = { 1, 0, -1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    void go(int& x, int& y, const int dir)
    {
        x = x + dx[dir], y = y + dy[dir];
    }

    void left(int& dir)
    {
        dir = (dir -1 + 4) % 4;
    }

    void right(int& dir)
    {
        dir = (dir + 1) % 4;
    }

public:
    bool isRobotBounded(string instructions) 
    {
        int x = 0, y = 0, dir = 0;

        for (const char c : instructions)
        {
            if (c == 'G') go(x, y, dir);
            else if (c == 'L') left(dir);
            else if (c == 'R') right(dir);
        }

        return (x == 0 && y == 0) || (dir != 0);
    }
};

int main()
{

	return 0;
}