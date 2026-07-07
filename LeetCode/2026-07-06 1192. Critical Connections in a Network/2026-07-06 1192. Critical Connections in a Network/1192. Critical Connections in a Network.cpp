#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n, time;
    vector<vector<int>> graph, ret;
    vector<int> visited, low;

    void dfs(int now, int parent)
    {
        visited[now] = low[now] = ++time;

        for (const int next : graph[now])
        {
            if (next == parent) continue;

            if (visited[next] == 0)
            {
                dfs(next, now);

                low[now] = min(low[now], low[next]);

                if (low[next] > visited[now])
                {
                    ret.push_back({ now, next });
                }
            }
            else
            {
                low[now] = min(low[now], visited[next]);
            }
        }
    }

public:
    Solution() : n(0), time(0) 
    {

    }

    vector<vector<int>> criticalConnections(int N, vector<vector<int>>& connections) 
    {
        n = N;
        graph.assign(n, vector<int>());
        visited.assign(n, 0);
        low.assign(n, 0);

        for (const vector<int>& edge : connections)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);

        return ret;
    }
};

int main()
{ 

    return 0;
}