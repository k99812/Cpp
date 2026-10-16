#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    typedef long long ll;

    struct Node
    {
        int now;
        ll cost;

        bool operator<(const Node& other) const
        {
            return cost > other.cost;
        }
    };

    const ll INF = 1e15;
    const int MOD = 1e9 + 7;

    int n;
    vector<vector<Node>> graph;

    int dijkstra()
    {
        priority_queue<Node> pq;
        vector<ll> dist(n, INF);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({ 0, 0 });

        while (pq.size())
        {
            auto [now, now_cost] = pq.top();
            pq.pop();

            if (dist[now] < now_cost) continue;

            for (const auto& [next, next_cost] : graph[now])
            {
                if (dist[next] > dist[now] + next_cost)
                {
                    ways[next] = ways[now];
                    dist[next] = dist[now] + next_cost;
                    pq.push({ next, dist[next]});
                }
                else if (dist[next] == dist[now] + next_cost)
                {
                    ways[next] = (ways[next] + ways[now]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }

public:
    int countPaths(int n, vector<vector<int>>& roads) 
    {
        this->n = n;
        graph.assign(n, vector<Node>());

        for (const vector<int>& v : roads)
        {
            int from = v[0], to = v[1], cost = v[2];

            graph[from].push_back({ to, cost });
            graph[to].push_back({ from, cost });
        }

        return dijkstra();
    }
};

int main()
{

	return 0;
}