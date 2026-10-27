#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    struct Node
    {
        int to, cost;

        bool operator<(const Node& other) const
        {
            return cost > other.cost;
        }
    };

    const int INF = INT_MAX;
    const int MOD = 1e9 + 7;

    int n;
    vector<int> dist, dp;
    vector<vector<Node>> graph;

    void dijkstra()
    {
        priority_queue<Node> pq;

        pq.push({ n, 0 });
        dist[n] = 0;

        while (pq.size())
        {
            auto [now, now_dist] = pq.top();
            pq.pop();

            if (now_dist > dist[now]) continue;

            for (const auto& [next, next_dist] : graph[now])
            {
                if (dist[next] > dist[now] + next_dist)
                {
                    dist[next] = dist[now] + next_dist;
                    pq.push({ next, dist[next] });
                }
            }
        }
    }

    int dfs(int now, int par)
    {
        if (now == 1) return 1;

        int& ret = dp[now];
        if (ret != -1) return ret;

        ret = 0;

        for (const auto [next, cost] : graph[now])
        {
            if (next == par) continue;

            if (dist[now] >= dist[next]) continue;

            ret = (ret + dfs(next, now)) % MOD;
        }

        return ret;
    }

public:
    Solution() : n(0) {}

    int countRestrictedPaths(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        dp.assign(n + 1, -1);
        dist.assign(n + 1, INF);
        graph.assign(n + 1, vector<Node>());

        for (const vector<int>& v : edges)
        {
            int from = v[0], to = v[1], cost = v[2];

            graph[from].push_back({ to, cost });
            graph[to].push_back({ from, cost });
        }

        dijkstra();

        return dfs(n, -1);
    }
};

int main()
{

	return 0;
}