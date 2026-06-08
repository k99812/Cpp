#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution 
{
    const int INF = 1e9;

    int n, k;
    vector<int> dist;
    vector<vector<pair<int, int>>> graph;

    void dijkstra()
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({ 0, k });
        dist[k] = 0;

        while (pq.size())
        {
            int now = pq.top().second, now_dist = pq.top().first;
            pq.pop();

            if (dist[now] != now_dist) continue;

            for (const pair<int, int>& edge : graph[now])
            {
                int next = edge.first, next_dist = edge.second;

                if (dist[next] > dist[now] + next_dist)
                {
                    dist[next] = dist[now] + next_dist;
                    pq.push({ dist[next], next });
                }
            }
        }
    }

public:
    Solution() : n(0), k(0)
    {

    }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        n = N;
        k = K;

        dist.assign(n + 1, INF);
        graph.assign(n + 1, vector<pair<int, int>>());

        for (const vector<int>& edge : times)
        {
            int from = edge[0], to = edge[1], cost = edge[2];
            graph[from].push_back({ to, cost });
        }

        dijkstra();

        int time = 0;
        for (int i = 1; i <= n; i++)
        {
            time = max(time, dist[i]);
        }

        return time == INF ? -1 : time;
    }
};

int main()
{
    int n = 4, k = 2;
    vector<vector<int>> input = { { 2, 1, 1 }, { 2, 3, 1 }, { 3, 4, 1 } };

    Solution sol = Solution();
    cout << sol.networkDelayTime(input, n, k) << "\n";

	return 0;
}