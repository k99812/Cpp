#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution 
{
    const int dy[4] = { -1, 0, 1, 0 };
    const int dx[4] = { 0, 1, 0, -1 };

    int n, id;
    vector<vector<int>> board, visited;
    unordered_map<int, int> id_map;

    void bfs(int y, int x, int id)
    {
        queue<pair<int, int>> q;

        visited[y][x] = id;
        q.push({ y, x });

        int cnt = 1;
        while (q.size())
        {
            int cy = q.front().first, cx = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i], nx = cx + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                if (visited[ny][nx] || board[ny][nx] == 0) continue;

                cnt++;
                visited[ny][nx] = id;
                q.push({ ny, nx });
            }
        }

        id_map[id] = cnt;
    }

public:
    Solution() : n(0), id(0)
    {

    }

    int largestIsland(vector<vector<int>>& grid) 
    {
        board = move(grid);
        n = board.size();
        visited.assign(n, vector<int>(n));

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 0 || visited[i][j] != 0) continue;

                bfs(i, j, ++id);
                ret = max(ret, id_map[id]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 1) continue;

                int sum = 1;
                unordered_set<int> id_set;

                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];

                    if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
                    if (!visited[ny][nx] || id_map.find(visited[ny][nx]) == id_map.end()) continue;

                    id_set.insert(visited[ny][nx]);
                }

                for (int id:id_set)
                {
                    sum += id_map[id];
                }

                ret = max(ret, sum);
            }
        }

        return ret;
    }
};

int main()
{
	return 0;
}