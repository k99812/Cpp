#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
    int n;
    vector<vector<int>> graph;

    void dfs(int node, int idx, vector<vector<int>>& ret)
    {
        if (node != idx)
        {
            ret[idx].push_back(node);
        }

        for (int next : graph[idx])
        {
            if (!ret[next].empty() && ret[next].back() == node) continue;

            dfs(node, next, ret);
        }
    }

public:
    Solution() : n(0) {}

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        this->n = n;
        graph.assign(n, vector<int>());

        for (const vector<int>& edge : edges)
        {
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
        }

        vector<vector<int>> ret(n, vector<int>());

        for (int i = 0; i < n; i++)
        {
            dfs(i, i, ret);
        }

        return ret;
    }
};

int main()
{

	return 0;
}