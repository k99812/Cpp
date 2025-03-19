#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<pair<int, int>>> graph;

pair<int, int> dijkstra(int start)
{
    vector<int> dist(n + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    while (pq.size())
    {
        int now_dist = pq.top().first, now = pq.top().second;
        pq.pop();

        if (dist[now] != now_dist) continue;

        for (pair<int, int>& p : graph[now])
        {
            int next = p.first, next_dist = p.second;

            if (dist[next] > dist[now] + next_dist)
            {
                dist[next] = dist[now] + next_dist;
                pq.push({ dist[next], next });
            }
        }
    }

    int max_dist = 0, node = start;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INT32_MAX && dist[i] > max_dist)
        {
            max_dist = dist[i];
            node = i;
        }
    }

    return { node, max_dist };
}

int main()
{
    cin >> n;

    graph.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        int from, to, weight;
        cin >> from;

        while (cin >> to)
        {
            if (to == -1) break;

            cin >> weight;

            graph[from].push_back({ to, weight });
        }
    }

    int node = dijkstra(1).first;

    int ret = dijkstra(node).second;

    cout << ret << "\n";

    return 0;
}