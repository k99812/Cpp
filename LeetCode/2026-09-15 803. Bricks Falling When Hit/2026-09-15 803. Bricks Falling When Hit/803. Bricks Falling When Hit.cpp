#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct UnionFind
{
    vector<int> parents, size;

public:
    UnionFind(int n)
    {
        parents.assign(n, 0);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    }

    int getRoot(int num)
    {
        if (num == parents[num]) return num;
        return parents[num] = getRoot(parents[num]);
    }

    bool unionParent(int a, int b)
    {
        int a_root = getRoot(a), b_root = getRoot(b);

        if (a_root != b_root)
        {
            if (b_root < a_root)
            {
                swap(a_root, b_root);
            }

            parents[b_root] = a_root;
            size[a_root] += size[b_root];
            return true;
        }

        return false;
    }

    int getSize(int num)
    {
        return size[getRoot(num)];
    }
};

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) 
    {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> board = grid;
        for (const vector<int>& hit : hits)
        {
            board[hit[0]][hit[1]] = 0;
        }

        UnionFind uf(n * m + 1);

        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                if (board[y][x] == 1)
                {
                    int id = y * m + x + 1;

                    if (y == 0) uf.unionParent(0, id);

                    if (y > 0 && board[y - 1][x]) uf.unionParent(id, (y - 1) * m + x + 1);
                    if (x > 0 && board[y][x - 1]) uf.unionParent(id, y * m + (x - 1) + 1);
                }
            }
        }

        vector<int> ret(hits.size(), 0);

        for (int i = hits.size() - 1; i >= 0; i--)
        {
            int y = hits[i][0], x = hits[i][1];

            if (grid[y][x] == 0) continue;

            int id = y * m + x + 1;
            int prev_size = uf.getSize(0);

            board[y][x] = 1;

            for (int d = 0; d < 4; d++)
            {
                int ny = y + dy[d], nx = x + dx[d];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m || board[ny][nx] == 0) continue;

                uf.unionParent(id, ny * m + nx + 1);
            }

            if (y == 0) uf.unionParent(0, id);

            int new_size = uf.getSize(0);

            if (uf.getRoot(id) == uf.getRoot(0))
            {
                ret[i] = max(0, new_size - prev_size - 1);
            }
        }

        return ret;
    }
};

int main()
{

	return 0;
}