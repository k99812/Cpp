#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct INFO
{
    int node, dist, bit;
};

class Solution 
{
    const int INF = 1e9;

    int n;
    vector<vector<int>> graph;

    int bfs()
    {
        queue<INFO> q;
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++)
        {
            q.push({ i, 0, 1 << i });
            visited[i][1 << i] = true;
        }

        while (q.size())
        {
            int now = q.front().node, now_dist = q.front().dist;
            int now_bit = q.front().bit;
            q.pop();

            for (const int next : graph[now])
            {
                int next_bit = now_bit | (1 << next);

                if (next_bit == ((1 << n) - 1))
                {
                    return now_dist + 1;
                }

                if (visited[next][next_bit]) continue;

                visited[next][next_bit] = true;
                q.push({ next, now_dist + 1, next_bit });
            }
        }

        return -1;
    }

public:
    Solution() : n(0)
    {

    }

    int shortestPathLength(vector<vector<int>>& input) 
    {
        n = input.size();
        graph = move(input);

        if (n == 1) return 0;

        return bfs();
    }
};

int main()
{

	return 0;
}