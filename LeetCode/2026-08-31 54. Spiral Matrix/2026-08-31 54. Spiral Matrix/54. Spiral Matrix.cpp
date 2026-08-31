#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int y, x, d;
};

class Solution 
{
    const int DIR = 4;
    const int dy[4] = { 0, 1, 0, -1 };
    const int dx[4] = { 1, 0, -1, 0 };

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> ret;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<Node> q;

        q.push({ 0, 0, 0 });
        visited[0][0] = true;
        ret.push_back(matrix[0][0]);

        while (q.size())
        {
            if (ret.size() == n * m) break;
 
            auto [y, x, d] = q.front();
            q.pop();

            int ny = y, nx = x;
            while (true)
            {
                ny = ny + dy[d], nx = nx + dx[d];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) break;
                if (visited[ny][nx]) break;

                visited[ny][nx] = true;
                ret.push_back(matrix[ny][nx]);
            }

            ny -= dy[d], nx -= dx[d];
            q.push({ ny, nx, (d + 1) % DIR });
        }

        return ret;
    }
};

int main()
{

	return 0;
}