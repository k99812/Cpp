#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<vector<pair<int, int>>> graph;
    vector<int> visited;

    int dfs(int now)
    {
        visited[now] = true;

        int sum = 0;
        for (const auto& [next, cost] : graph[now])
        {
            if (visited[next]) continue;

            sum += cost + dfs(next);
        }

        return sum;
    }

public:
    Solution() : n(0) {}

    int minReorder(int n, vector<vector<int>>& connections) 
    {
        this->n = n;
        graph.assign(n, vector<pair<int, int>>());
        visited.assign(n, 0);

        for (const vector<int>& connection : connections)
        {
            int from = connection[0], to = connection[1];

            graph[from].push_back({ to, 1 });
            graph[to].push_back({ from, 0 });
        }

        return dfs(0);
    }
};

int main()
{

	return 0;
}