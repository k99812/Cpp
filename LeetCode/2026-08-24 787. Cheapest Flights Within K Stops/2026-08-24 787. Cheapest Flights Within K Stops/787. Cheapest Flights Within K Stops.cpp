#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node
{
    int to, cost;
};

class Solution 
{
    const int INF = 1e9;

    int n, k, start, end;
    vector<vector<Node>> graph;

    int bfs()
    {
        queue<Node> q;
        vector<int> dist(n, INF);

        q.push({ start, 0});
        dist[start] = 0;

        int step = 0;

        while (q.size() && step <= k)
        {
            int size = q.size();

            vector<int> temp_dist = dist;

            while (size--)
            {
                const auto [now, cost] = q.front();
                q.pop();

                for (const auto [next, next_cost] : graph[now])
                {
                    if (temp_dist[next] > dist[now] + next_cost)
                    {
                        temp_dist[next] = dist[now] + next_cost;
                        q.push({ next, temp_dist[next] });
                    }
                }
            }

            dist = temp_dist;
            step++;
        }

        return dist[end] == INF ? -1 : dist[end];
    }

public:
    int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dst, int K) 
    {
        n = N, k = K;
        start = src, end = dst;
        graph.assign(n, vector<Node>());

        for (const vector<int>& v : flights)
        {
            graph[v[0]].push_back({ v[1], v[2]});
        }

        return bfs();
    }
};

int main()
{

	return 0;
}