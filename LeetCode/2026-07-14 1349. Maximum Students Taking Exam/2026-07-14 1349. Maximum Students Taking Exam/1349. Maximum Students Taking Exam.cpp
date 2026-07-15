#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    const int dy[6] = { -1, 0, 1, -1, 0, 1 };
    const int dx[6] = { -1, -1, -1, 1, 1, 1 };

    int n, m;
    vector<int> match, visited;
    vector<vector<int>> graph;

    bool dfs(int now)
    {
        for (int next : graph[now])
        {
            if (visited[next]) continue;

            visited[next] = true;

            if (match[next] == -1 || dfs(match[next]))
            {
                match[next] = now;
                return true;
            }
        }

        return false;
    }

public:
    int maxStudents(vector<vector<char>>& seats) 
    {
        n = seats.size();
        m = seats[0].size();
        int total = n * m;

        graph.assign(total, vector<int>());
        match.assign(total, -1);

        int seats_cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (seats[i][j] == '#') continue;

                seats_cnt++;

                if (j % 2 == 0)
                {
                    int id = i * m + j;

                    for (int d = 0; d < 6; d++)
                    {
                        int ny = i + dy[d], nx = j + dx[d];

                        if (ny < 0 || nx < 0 || ny >= n || nx >= m || seats[ny][nx] == '#') continue;

                        int next_id = ny * m + nx;
                        graph[id].push_back(next_id);
                    }
                }
            }
        }

        int match_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j += 2)
            {
                if (seats[i][j] == '#') continue;

                visited.assign(total, false);

                int id = i * m + j;
                if (dfs(id))
                {
                    match_cnt++;
                }
            }
        }

        return seats_cnt - match_cnt;
    }
};

int main()
{

    return 0;
}